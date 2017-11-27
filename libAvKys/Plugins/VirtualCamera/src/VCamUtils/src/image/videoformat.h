/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2017  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#ifndef VIDEOFORMAT_H
#define VIDEOFORMAT_H

#include <cstdint>
#include <vector>

#define MKFOURCC(a, b, c, d) \
    (((a & 0xff) << 24) | ((b & 0xff) << 16) | ((c & 0xff) << 8) | (d & 0xff))

namespace AkVCam
{
    typedef uint32_t FourCC;

    struct VideoFormatStruct
    {
            FourCC fourcc;
            int width;
            int height;
            double frameRate;
    };

    class VideoFormat
    {
        public:
            VideoFormat();
            VideoFormat(FourCC fourcc,
                        int width,
                        int height,
                        const std::vector<double> &frameRates={});
            VideoFormat(const VideoFormat &other);
            VideoFormat(const VideoFormatStruct &videoFormatStruct);
            VideoFormat &operator =(const VideoFormat &other);
            VideoFormat &operator =(const VideoFormatStruct &videoFormatStruct);
            ~VideoFormat();

            FourCC fourcc() const;
            FourCC &fourcc();
            int width() const;
            int &width();
            int height() const;
            int &height();
            std::vector<double> frameRates() const;
            std::vector<double> &frameRates();
            std::vector<std::pair<double, double>> frameRateRanges() const;
            double minimumFrameRate() const;
            VideoFormatStruct toStruct() const;

        private:
            FourCC m_fourcc;
            int m_width;
            int m_height;
            std::vector<double> m_frameRates;
    };
}

#endif // VIDEOFORMAT_H
