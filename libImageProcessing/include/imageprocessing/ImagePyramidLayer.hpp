/*
 * ImagePyramidLayer.hpp
 *
 *  Created on: 15.02.2013
 *      Author: poschmann
 */

#ifndef IMAGEPYRAMIDLAYER_HPP_
#define IMAGEPYRAMIDLAYER_HPP_

#include "opencv2/core/core.hpp"

namespace imageprocessing {

/**
 * Layer of an image pyramid.
 */
class ImagePyramidLayer {
public:

	/**
	 * Constructs a new pyramid layer.
	 *
	 * @param[in] index The index of this layer (0 is the original sized layer).
	 * @param[in] scaleFactor The scale factor of this layer compared to the original image.
	 * @param[in] scaledImage The scaled image.
	 */
	explicit ImagePyramidLayer(int index, double scaleFactor, const cv::Mat& scaledImage);

	/**
	 * Computes the scaled representation of an original value (coordinate, size, ...) and rounds accordingly.
	 *
	 * @param[in] value The value in the original image.
	 * @return The corresponding value in this layer.
	 */
	int getScaled(int value) const {
		return cvRound(value * scaleFactor);
	}

	/**
	 * Computes the original representation of a scaled value (coordinate, size, ...) and rounds accordingly.
	 *
	 * @param[in] value The value in this layer.
	 * @return corresponding The value in the original image.
	 */
	int getOriginal(int value) const {
		return cvRound(value / scaleFactor);
	}

	/**
	 * @return The size of this layer (size of the scaled image).
	 */
	cv::Size getSize() const {
		return cv::Size(scaledImage.cols, scaledImage.rows);
	}

	/**
	 * @return The index of this layer (0 is the original sized layer).
	 */
	int getIndex() const {
		return index;
	}

	/**
	 * @return The scale factor of this level compared to the original image.
	 */
	double getScaleFactor() const {
		return scaleFactor;
	}

	/**
	 * @return The scaled image.
	 */
	const cv::Mat& getScaledImage() const {
		return scaledImage;
	}

	/**
	 * @return The scaled image.
	 */
	cv::Mat& getScaledImage() {
		return scaledImage;
	}

private:

	int index;          ///< The index of this layer (0 is the original sized layer).
	double scaleFactor; ///< The scale factor of this layer compared to the original image.
	cv::Mat scaledImage;    ///< The scaled image.
};

} /* namespace imageprocessing */
#endif /* IMAGEPYRAMIDLAYER_HPP_ */
