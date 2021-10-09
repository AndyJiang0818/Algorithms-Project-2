/*
 * Xihao Jiang
 * CSCI 335
 * Homework 2
 *
 * Header file for points2d program, most of the method is brute forced.
 * Added two private variables, row and column for ReadPoints2D function utilized stl array for this program.
 */

#ifndef CSCI335_HOMEWORK2_POINTS2D_H_
#define CSCI335_HOMEWORK2_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of this class,
// and its sample usage.
template<typename Object>
class Points2D {
public:
	// Default "big five" -- you have to alter them for your assignment.
	// That means that you will remove the "= default" statement.
	//  and you will provide an implementation for it.

	// Zero-parameter constructor.
	// Set size to 0.
	// Set the sequence as nullptr;
	Points2D() :
			sequence_(nullptr), size_(0) {

	}

	// Copy-constructor.
	// Copy the array and size
	// If copy file is nullptr, return.
	// Return Points2D object with copied value.
	Points2D(const Points2D &rhs) :
			sequence_(rhs.sequence_), size_(rhs.size_) {
		if (rhs.sequence_ == nullptr)
			return;
		sequence_ = new std::array<Object, 2>[size_];
		for (size_t i = 0; i < size_; i++) {
			for (int j = 0; j < 2; j++) {
				sequence_[i][j] = rhs.sequence_[i][j];
			}
		}
	}

	// Copy-assignment. If you have already written
	// the copy-constructor and the move-constructor
	// you can just use:
	// {
	// Points2D copy = rhs;
	// std::swap(*this, copy);
	// return *this;
	// }
	Points2D& operator=(const Points2D &rhs) {
		if (this == &rhs) {
			return *this;
		}
		if (sequence_ != nullptr) {
			delete[] sequence_;
			sequence_ = nullptr;
			size_ = 0;
		}
		sequence_ = new std::array<Object, 2>[rhs.size_];
		size_ = rhs.size_;
		for (size_t i = 0; i < size_; i++) {
			for (int j = 0; j < 2; j++) {
				sequence_[i][j] = rhs.sequence_[i][j];
			}
		}
		return *this;
	}

	// Move-constructor.
	Points2D(Points2D &&rhs) :
			sequence_(rhs.sequence_), size_(rhs.size_) {
		rhs.sequence_ = nullptr;
		rhs.size_ = 0;
	}

	// Move-assignment.
	// Just use std::swap() for all variables.
	// Utilized std::swap() for move-assignment.
	Points2D& operator=(Points2D &&rhs) {
		if (this == &rhs) {
			return *this;
		}

		std::swap(sequence_, rhs.sequence_);
		std::swap(size_, rhs.size_);

		return *this;
	}

	// Destructor.
	// Delete allocated space for the array.
	// Set size to 0.
	// Set pointer to null.
	~Points2D() {
		if (sequence_ != nullptr) {
			delete[] sequence_;
			size_ = 0;
			sequence_ = nullptr;
		}
	}

	// End of big-five.

	// One parameter constructor.
	// Take in the array item.
	// Allocate space as the size of the array - 1.
	// Copy the value in the array item.
	// Hardcode on the copying the value because we only take one array item.
	// No point making it complicated.
	Points2D(const std::array<Object, 2> &item) {
		size_ = item.size() - 1;
		sequence_ = new std::array<Object, 2>[size_];
		sequence_[0][0] = item[0];
		sequence_[0][1] = item[1];
	}

	// Read a chain from standard input.
	void ReadPoints2D() {
		// Part of code included (without error checking).
		// Used the professor's code.
		std::string input_line;
		std::getline(std::cin, input_line);
		std::stringstream input_stream(input_line);
		if (input_line.empty())
			return;
		// Read size of sequence (an integer).
		// Only read once.
		int size_of_sequence;
		input_stream >> size_of_sequence;
		// Set size_ to the size_of_sequence.
		size_ = size_of_sequence;
		// Allocate space for sequence.
		sequence_ = new std::array<Object, 2>[size_of_sequence];

		Object token;
		for (int i = 0; input_stream >> token; ++i) {
			// Read coordinates.
			// Fill sequence_ here.
			// Once it reads a token, put in appropriate place, such as [0][0],[0][1],[1][0],[1][1].
			// [x][y] x always increment up and y will flip between 0 and 1.
			// Row only gets updated once the column is completely filled.
			// Utilized two private variables: row and column
			sequence_[row][column] = token;
			if (column == 0) {
				column++;
			} else {
				column--;
				row++;
			}

		}

	}

	// Return size_.
	size_t size() const {
		return size_;
	}

	// @location: an index to a location in the given sequence.
	// @returns the point at @location.
	// const version.
	// abort() if out-of-range.
	const std::array<Object, 2>& operator[](size_t location) const {
		// If the sequence_ does not exist, abort.
		if (sequence_ == nullptr) {
			abort();
		}
		if (location > size_) {
			abort();
		}
		return sequence_[location];
	}

	//  @c1: A sequence.
	//  @c2: A second sequence.
	//  @return their sum. If the sequences are not of the same size, append the
	//    result with the remaining part of the larger sequence.
	friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
		Points2D result; //create a Points2D object sicnce it is the return type

		// Brute force way to append two array object.
		// If one object size is greater than another.
		// Take the larger size and allocate space for that size.
		// Get the sum from common size, hence using the smaller size_.
		// Then starting from the smaller size_, append the rest of the array object.
		if (c1.size_ > c2.size_) {
			result.sequence_ = new std::array<Object, 2>[c1.size_];
			result.size_ = c1.size_;
			for (size_t i = 0; i < c2.size_; i++) {
				for (int j = 0; j < 2; j++) {
					result.sequence_[i][j] = c1.sequence_[i][j]
							+ c2.sequence_[i][j];
				}
			}
			for (size_t i = c2.size_; i < c1.size_; i++) {
				for (int j = 0; j < 2; j++) {
					result.sequence_[i][j] = c1.sequence_[i][j];
				}
			}
		} else if (c1.size_ < c2.size_) {
			result.size_ = c2.size_;
			result.sequence_ = new std::array<Object, 2>[c2.size_];
			for (size_t i = 0; i < c1.size_; i++) {
				for (int j = 0; j < 2; j++) {
					result.sequence_[i][j] = c1.sequence_[i][j]
							+ c2.sequence_[i][j];
				}
			}
			for (size_t i = c1.size_; i < c2.size_; i++) {
				for (int j = 0; j < 2; j++) {
					result.sequence_[i][j] = c2.sequence_[i][j];
				}
			}
		}
		// If size_ are equal, just do arithmetic on the object.
		else if (c2.size_ == c1.size_) {
			result.size_ = c2.size_;
			result.sequence_ = new std::array<Object, 2>[c2.size_];
			for (size_t i = 0; i < result.size_; i++) {
				for (int j = 0; j < 2; j++) {
					result.sequence_[i][j] = c1.sequence_[i][j]
							+ c2.sequence_[i][j];
				}
			}

		}

		// Return a Points2d object.
		return result;

	}

	// Overloading the << operator.
	friend std::ostream& operator<<(std::ostream &out,
			const Points2D &some_points2d) {
		// If the size is 0, print out an empty parentheses.
		if (some_points2d.size() == 0) {
			out << "()";
		}
		// For any other size object, simple for loop is suffice.
		for (size_t i = 0; i < some_points2d.size(); i++) {
			out << "(" << some_points2d.sequence_[i][0] << ", "
					<< some_points2d.sequence_[i][1] << ") ";
		}
		std::cout << std::endl;
		return out;
	}

private:
	// Sequence of points.
	std::array<Object, 2> *sequence_;
	// Size of the sequence.
	size_t size_;
	// Add row and column for reading the sequence.
	int row = 0;
	int column = 0;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK2_POINTS2D_H_
