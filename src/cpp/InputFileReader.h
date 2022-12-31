//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef INPUT_FILE_READER_H
#define INPUT_FILE_READER_H

#include <filesystem>
#include <string>

namespace AdventOfCode::InputFileReader {

    using HandleLineCallbackFunction = std::function<void(std::string &&)>;

    /**
     * Read lines from the file, one line at a time.
     *
     * @param inputFilePath path to read from
     * @param handleLine callback to process each line
     */
    void readLines(const std::filesystem::path &inputFilePath, const HandleLineCallbackFunction &&handleLine);

} // AdventOfCode::InputFileReader

#endif // INPUT_FILE_READER_H
