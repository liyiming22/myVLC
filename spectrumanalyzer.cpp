#include "spectrumanalyzer.h"

SpectrumAnalyzer::SpectrumAnalyzer(QObject *parent) : QObject(parent)
{
    m_fft = nullptr;
    for (int i = 0; i < numSamples; i++) {
        float window = 0.5f * float(1 - qCos((2 * M_PI * i) / (numSamples - 1)));
        m_window.push_back(window);
    }
    qDebug() << "contructed!";
}

SpectrumAnalyzer::~SpectrumAnalyzer()
{
    if (m_fft)
        free(m_fft);
}

void SpectrumAnalyzer::calculateSpectrum(QAudioBuffer buf)
{
    int sampleRate = buf.format().sampleRate();
    QAudioBuffer :: S16S * samples = buf.data<QAudioBuffer :: S16S>();
    m_spectrum.clear();
    QVector<SpectrumStruct> pNullVector;
    m_spectrum.swap(pNullVector);

    kiss_fft_cpx inbuf[numSamples];
    kiss_fft_cpx outbuf[numSamples];

    // Initialize data array
    for (int i = 0; i < numSamples; i++) {
        float realSample = samples[i].right;
        float window = m_window[i];
        float windowedSample = realSample * window;
        inbuf[i].r = windowedSample;
        inbuf[i].i = 0;
    }

    // Calculate the FFT
    m_fft = kiss_fft_alloc(numSamples, 0, nullptr, nullptr);
    kiss_fft(m_fft, inbuf, outbuf);

    // Analyze output to obtain amplitude and phase for each frequency
    for (int i = 2; i <= numSamples / 2; i++) {
        // Calculate frequency of this complex sample
        struct SpectrumStruct thisSP;
        thisSP.frequency = float(i * sampleRate / numSamples);

        kiss_fft_cpx cpx = outbuf[i];

        float real = cpx.r;
        float imag = 0;

        if (i > 0 && i < numSamples / 2) {
            kiss_fft_cpx cpx = outbuf[numSamples / 2 + i];
            imag = cpx.r;
        }

        const float thisMagnitude = float(qSqrt(qreal(real * real + imag * imag)));
        float thisAmplitude = SpectrumAnalyserMultiplier * float(qLn(qreal(thisMagnitude)));
        qDebug() << thisSP.frequency << "\t" << thisAmplitude;
        // Bound amplitude to [0, 1]
//        if (thisAmplitude > 1)  thisAmplitude -= 1;
//        else if (thisAmplitude < 0)   thisAmplitude = 0;
//        thisAmplitude = qBound(float(0), thisAmplitude, float(1));
        thisSP.amplitude = thisAmplitude;
        m_spectrum.push_back(thisSP);
//        qDebug() << thisSP.frequency << "\t" << thisSP.amplitude;
    }
    emit spectrumChanged(m_spectrum);
}
