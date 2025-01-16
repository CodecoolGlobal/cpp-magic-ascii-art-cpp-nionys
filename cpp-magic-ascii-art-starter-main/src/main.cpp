//
// Created by Patrik on 13/01/2025.
//

#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "pipeline/ImageConverter.h"
#include "util/fileUtil.h"
#include "util/parseUtil.h"

#define DEFAULT_RESOLUTION (-1)
#define SOURCE_FOLDER_PATH "../pics/"



        using namespace std;

struct InputArgs {
    const string sourceFile, targetFile;
    // use DEFAULT_RESOLUTION to keep source height
    const int targetHeight, targetWidth;

    // defined constructor to prevent incomplete initialization

    InputArgs(string sourceFile, string targetFile, const int targetHeight, const int targetWidth) :
        sourceFile(std::move(sourceFile)), targetFile(std::move(targetFile)), targetHeight(targetHeight),
        targetWidth(targetWidth) {}
};

InputArgs parseArgs(const int argc, char **argv) {
    if (!(argc & 1))
        throw invalid_argument("unpaired argument");


    string sourceFile, targetFile;
    int targetHeight{DEFAULT_RESOLUTION}, targetWidth{DEFAULT_RESOLUTION};

    for (int i = 1; i < argc - 1; i++) {
        string key = argv[i];
        string value = argv[++i];
        if (key == "-img") {
            sourceFile = value;
        } else if (key == "-target") {
            targetFile = value;
        } else if (key == "-height") {
            targetHeight = parseInt(value);
        } else if (key == "-width") {
            targetWidth = parseInt(value);
        } else {
            throw invalid_argument("unknown option");
        }
    }
    return {sourceFile, targetFile, targetHeight, targetWidth};
}

int main(int argc, char **argv) {


    InputArgs testArgs[] = {{"test1.jpg", "jpg_1.txt", -1, -1},
                            {"test2.jpg", "jpg_2.txt", -1, -1},
                            {"test1.bmp", "bmp_1.txt", -1, -1},
                            {"test2.bmp", "bmp_2.txt", -1, -1},
                            {"test1.png", "png_1.txt", -1, -1},
                            {"test2.png", "png_2.txt", -1, -1}

    };
    for (const InputArgs &args: testArgs) {
        try {
            // InputArgs args = parseArgs(argc, argv);

            ImageConverter imageConverter;
            imageConverter.load(SOURCE_FOLDER_PATH + args.sourceFile);
            const string asciiArt = (args.targetHeight != DEFAULT_RESOLUTION && args.targetWidth != DEFAULT_RESOLUTION)
                                            ? imageConverter.convert(args.targetHeight, args.targetWidth)
                                            : imageConverter.convert();


            writeToFile(args.targetFile, asciiArt);
        } catch (const exception &e) {
            cerr << "ERROR: " << e.what() << endl;
            system("pause");
            exit(1);
        }
    }
}
