#ifndef SPECTRUMANALYZER_H
#define SPECTRUMANALYZER_H

#include <QtCore>
#include <QtMultimedia>
#include <kiss_fft.h>

// Fudge factor used to calculate the spectrum bar heights
#define SpectrumAnalyserMultiplier float(0.15)

// Needs to be a power of two
#define numSamples 128

struct SpectrumStruct
{
    float frequency;
    float amplitude;
};

class SpectrumAnalyzer : public QObject
{
    Q_OBJECT
public:
    explicit SpectrumAnalyzer(QObject *parent = nullptr);
    ~SpectrumAnalyzer();

signals:
    void spectrumChanged(QVector<SpectrumStruct>);

public slots:
    void calculateSpectrum(QAudioBuffer);

private:
    kiss_fft_cfg m_fft;
    QVector<SpectrumStruct> m_spectrum;
    QVector<float> m_window;
};

#endif // SPECTRUMANALYZER_H
