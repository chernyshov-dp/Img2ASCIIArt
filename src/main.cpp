#include <iostream>
#include <vector>
#include <string>
#include <png++/png.hpp>
#include <stdexcept>

const std::string ASCII_CHARS = "@%#*+=-:. ";

// Function to read PNG image from file
png::image<png::rgb_pixel> readImagePNG(const std::string& imagePath) {
    png::image<png::rgb_pixel> image(imagePath);
    return image;
}

// Function to convert color image to grayscale
std::vector<std::vector<int>> convertToGray(const png::image<png::rgb_pixel>& image, int outputWidth, int outputHeight) {
    int width = image.get_width();
    int height = image.get_height();

    std::vector<std::vector<int>> grayValues(outputHeight, std::vector<int>(outputWidth, 0));

    for (int y = 0; y < outputHeight; y++) {
        for (int x = 0; x < outputWidth; x++) {
            int originalX = (x * width) / outputWidth;
            int originalY = (y * height) / outputHeight;

            png::rgb_pixel pixel = image.get_pixel(originalX, originalY);
            grayValues[y][x] = (pixel.red + pixel.green + pixel.blue) / 3;
        }
    }

    return grayValues;
}

// Function to convert grayscale image to ASCII art
std::string convertToAscii(const std::vector<std::vector<int>>& grayValues) {
    std::string asciiArt;
    for (const auto& row : grayValues) {
        for (int grayValue : row) {
            int index = (grayValue * ASCII_CHARS.size()) / 255;
            asciiArt += ASCII_CHARS[index];
        }
        asciiArt += '\n';
    }
    return asciiArt;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        std::cout << "Usage: " << argv[0] << " <image_path> [output_width output_height]" << std::endl;
        return 1;
    }

    std::string imagePath = argv[1];

    int outputWidth = 100; // Default width for output image
    int outputHeight = 100; // Default height for output image

    // If output width and height are provided, read them
    if (argc == 4) {
        outputWidth = std::stoi(argv[2]);
        outputHeight = std::stoi(argv[3]);
    }

    try {
        png::image<png::rgb_pixel> image = readImagePNG(imagePath);

        auto grayValues = convertToGray(image, outputWidth, outputHeight);

        std::string asciiArt = convertToAscii(grayValues);

        std::cout << asciiArt << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error loading image: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
