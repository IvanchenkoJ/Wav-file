#ifndef WAVREADER_H
#define WAVREADER_H

#include "AudioFile.h"

#include <QVector>
#include <iostream>

class WavReader {
public:
    QVector<double> readSamples(std::string file) {
        AudioFile<double> audioFile;
        audioFile.load(file);
        int numSamples = audioFile.getNumSamplesPerChannel();
        QVector<double> samples(numSamples);

        int channel = 0;
        for (int i = 0; i < numSamples; i++)
        {
            samples[i] = audioFile.samples[channel][i];
        }
        return samples;
    }

    QVector<double> readTime(std::string file) {
        AudioFile<double> audioFile;
        audioFile.load(file);
        int numSamples = audioFile.getNumSamplesPerChannel();
        QVector<double> time(numSamples);

        for (int i = 0; i < numSamples; i++)
        {
            time[i] = i;
        }
        return time;
    }
};

#endif // WAVREADER_H
