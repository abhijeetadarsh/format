#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int modifyFiles(std::string inputFileName, std::string tempFileName, std::string message) {
    std::string line;

    // Open the input file
    std::ifstream inputFile(inputFileName);

    if (!inputFile) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return 1;
    }

    // Open a temporary file for writing
    std::ofstream tempFile(tempFileName);

    if (!tempFile) {
        std::cerr << "Error: Unable to create the temporary file." << std::endl;
        return 1;
    }

    // Read each line from the input file
    while (std::getline(inputFile, line)) {
        // Skip lines that start with '#'
        if (line.size() > 0 && line[0] == '#') {
            continue;
        }

        // Write non-comment lines to the temporary file
        tempFile << line << std::endl;
    }

    // Close both files
    inputFile.close();
    tempFile.close();

    // Rename the temporary file to the input file
    if (std::rename(tempFileName.c_str(), inputFileName.c_str()) != 0) {
        std::cerr << "Error: Unable to update the input file." << std::endl;
        return 1;
    }

    // Open the input file again to add a new line at the beginning
    std::ifstream inputFileForUpdate(inputFileName);

    if (!inputFileForUpdate) {
        std::cerr << "Error: Unable to open the input file for updating." << std::endl;
        return 1;
    }

    // Create a string stream to hold the contents of the input file
    std::stringstream fileContents;
    fileContents << message << std::endl;

    // Read the existing contents of the input file and append to the string stream
    while (std::getline(inputFileForUpdate, line)) {
        fileContents << line << std::endl;
    }

    inputFileForUpdate.close();

    // Open the input file again for writing
    std::ofstream inputFileUpdated(inputFileName);

    if (!inputFileUpdated) {
        std::cerr << "Error: Unable to open the input file for writing." << std::endl;
        return 1;
    }

    // Write the updated contents to the input file
    inputFileUpdated << fileContents.str();

    inputFileUpdated.close();

    std::cout << "File updated successfully !" << std::endl;

    return 0;
}
int blankLineRemover(std::string inputFileName, std::string outputFileName) {
    std::string line;

    // Open the input file
    std::ifstream inputFile(inputFileName);

    if (!inputFile) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return 1;
    }

    // Open the output file for writing
    std::ofstream outputFile(outputFileName);

    if (!outputFile) {
        std::cerr << "Error: Unable to create the output file." << std::endl;
        inputFile.close();
        return 1;
    }

    // Read each line from the input file
    while (std::getline(inputFile, line)) {
        // Skip the line if it's blank (empty or containing only whitespace)
        if (!line.empty() && line.find_first_not_of(' ') != std::string::npos) {
            // Write non-blank lines to the output file
            outputFile << line << std::endl;
        }
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    std::cout << "Blank lines removed successfully !" << std::endl;

    return 0;
}
int preprocessorRunner(const char *inputFileName) {
    std::ifstream input_file(inputFileName);
    std::ofstream temp_file(".XTqXRj#15!.cpp");

    if (!input_file) {
        std::cerr << "Error opening " << inputFileName << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        if (line.find("#include") != 0) {
            temp_file << line << std::endl;
        }
    }

    // Create the command to run the preprocessor
    std::string command = "g++ -E .XTqXRj#15!.cpp -o .LB6hNm82#j.cpp";

    // Use system() to execute the command
    int result = system(command.c_str());

    // Check if the preprocessing was successful
    if (result == 0) {
        std::cout << "Preprocessing successful !" << std::endl;
    } else {
        std::cout << "Preprocessing failed :(" << std::endl;
    }
    return 0;
}
std::vector<std::string> ascii_arts =
    {
//         R"(

// **                              ___,--------,____
// **                      __--~~~~                 ~~---,_
// **                   ,-'                  __,--,_       `\,___,-,__
// **                ,-'                 __/'/-~~~\  `  ` . '    , |  `~~\
// **             _/`      _/~~      '~~   \,_\_ O /        '  '~_/'      `\
// **           /'        '                   =-'~~  _  /  ~   /'          `\
// **        _/'  /~                            ,--,____,-----|,_,-,_       `\
// **    _,/'    '              ,-'      _      `~'------'~~~~~--    `~~~~\  |
// ** ,-'             /~       '    ,-~~~         _,       ,-=~~~~~~~~~~~~'| |
// **~              .'             '         ,   '      /~`                |/
// **                                  /' ,/'       _/~'
// **                   ,       /    /`          _/~ 
// **        /~        /      /`               /' 
// **      .'                                /' 
// **                       /'      .      /
// **                      `       /'     | 
// **                                    '
// )",
//         R"(
// **                              /T /I
// **                               / |/ | .-~/
// **                           T\ Y  I  |/  /  _
// **          /T               | \I  |  I  Y.-~/
// **         I l   /I       T\ |  |  l  |  T  /
// **      T\ |  \ Y l  /T   | \I  l   \ `  l Y
// **  __  | \l   \l  \I l __l  l   \   `  _. |
// **  \ ~-l  `\   `\  \  \\ ~\  \   `. .-~   |
// **   \   ~-. "-.  `  \  ^._ ^. "-.  /  \   |
// ** .--~-._  ~-  `  _  ~-_.-"-." ._ /._ ." ./
// **  >--.  ~-.   ._  ~>-"    "\\   7   7   ]
// ** ^.___~"--._    ~-{  .-~ .  `\ Y . /    |
// **  <__ ~"-.  ~       /_/   \   \I  Y   : |
// **    ^-.__           ~(_/   \   >._:   | l______
// **        ^--.,___.-~"  /_/   !  `-.~"--l_ /     ~"-.
// **               (_/ .  ~(   /'     "~"--,Y   -=b-. _)
// **                (_/ .  \  :           / l      c"~o \
// **                 \ /    `.    .     .^   \_.-~"~--.  )
// **                  (_/ .   `  /     /       !       )/
// **                   / / _.   '.   .':      /        '
// **                   ~(_/ .   /    _  `  .-<_
// **                     /_/ . ' .-~" `.  / \  \          ,z=.
// **                     ~( /   '  :   | K   "-.~-.______//
// **                       "-,.    l   I/ \_    __{--->._(==.
// **                        //(     \  <    ~"~"     //
// **                       /' /\     \  \     ,v=.  ((
// **                     .^. / /\     "  }__ //===-  `
// **                    / / ' '  "-.,__ {---(==-       -Row
// **                  .^ '       :  T  ~"   ll
// **                 / .  .  . : | :!        \\
// **                (_/  /   | | j-"          ~^
// **                  ~-<_(_.^-~"
// )",
        R"(

**                   /^v^\
**         /^v^\                      /^v^\
**                /^v^\
**
**    /^v^\
)",
        R"(

**                       | 
**   ____________    __ -+-  ____________ 
**   \_____     /   /_ \ |   \     _____/
**    \_____    \____/  \____/    _____/
**     \_____                    _____/
**        \___________  ___________/
**                  /____\
)",
        R"(

**         .---.        .-----------
**        /     \  __  /    ------
**       / /     \(  )/    -----
**      //////   ' \/ `   ---
**     //// / // :    : ---
**    // /   /  /`    '--
**   //          //..\\
**          ====UU====UU====
**              '//||\\`
**                ''``
)",
// R"(
//                                             ,   ,
//                                         $,  $,     ,
//                                         "ss.$ss. .s'
//                                 ,     .ss$$$$$$$$$$s,
//                                 $. s$$$$$$$$$$$$$$`$$Ss
//                                 "$$$$$$$$$$$$$$$$$$o$$$       ,
//                                s$$$$$$$$$$$$$$$$$$$$$$$$s,  ,s
//                               s$$$$$$$$$"$$$$$$""""$$$$$$"$$$$$,
//                               s$$$$$$$$$$s""$$$$ssssss"$$$$$$$$"
//                              s$$$$$$$$$$'         `"""ss"$"$s""
//                              s$$$$$$$$$$,              `"""""$  .s$$s
//                              s$$$$$$$$$$$$s,...               `s$$'  `
//                          `ssss$$$$$$$$$$$$$$$$$$$$####s.     .$$"$.   , s-
//                            `""""$$$$$$$$$$$$$$$$$$$$#####$$$$$$"     $.$'
//                                  "$$$$$$$$$$$$$$$$$$$$$####s""     .$$$|
//                                   "$$$$$$$$$$$$$$$$$$$$$$$$##s    .$$" $
//                                    $$""$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"   `
//                                   $$"  "$"$$$$$$$$$$$$$$$$$$$$S""""'
//                              ,   ,"     '  $$$$$$$$$$$$$$$$####s
//                              $.          .s$$$$$$$$$$$$$$$$$####"
//                  ,           "$s.   ..ssS$$$$$$$$$$$$$$$$$$$####"
//                  $           .$$$S$$$$$$$$$$$$$$$$$$$$$$$$#####"
//                  Ss     ..sS$$$$$$$$$$$$$$$$$$$$$$$$$$$######""
//                   "$$sS$$$$$$$$$$$$$$$$$$$$$$$$$$$########"
//            ,      s$$$$$$$$$$$$$$$$$$$$$$$$#########""'
//            $    s$$$$$$$$$$$$$$$$$$$$$#######""'      s'         ,
//            $$..$$$$$$$$$$$$$$$$$$######"'       ....,$$....    ,$
//             "$$$$$$$$$$$$$$$######"' ,     .sS$$$$$$$$$$$$$$$$s$$
//               $$$$$$$$$$$$#####"     $, .s$$$$$$$$$$$$$$$$$$$$$$$$s.
//    )          $$$$$$$$$$$#####'      `$$$$$$$$$###########$$$$$$$$$$$.
//   ((          $$$$$$$$$$$#####       $$$$$$$$###"       "####$$$$$$$$$$
//   ) \         $$$$$$$$$$$$####.     $$$$$$###"             "###$$$$$$$$$   s'
//  (   )        $$$$$$$$$$$$$####.   $$$$$###"                ####$$$$$$$$s$$'
//  )  ( (       $$"$$$$$$$$$$$#####.$$$$$###' -Tua Xiong     .###$$$$$$$$$$"
//  (  )  )   _,$"   $$$$$$$$$$$$######.$$##'                .###$$$$$$$$$$
//  ) (  ( \.         "$$$$$$$$$$$$$#######,,,.          ..####$$$$$$$$$$$"
// (   )$ )  )        ,$$$$$$$$$$$$$$$$$$####################$$$$$$$$$$$"
// (   ($$  ( \     _sS"  `"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$S$$,
//  )  )$$$s ) )  .      .   `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"'  `$$
//   (   $$$Ss/  .$,    .$,,s$$$$$$##S$$$$$$$$$$$$$$$$$$$$$$$$S""        '
//     \)_$$$$$$$$$$$$$$$$$$$$$$$##"  $$        `$$.        `$$.
//         `"S$$$$$$$$$$$$$$$$$#"      $          `$          `$
//             `"""""""""""""'         '           '           '

// )",
//         R"(
// **    ,_,        ,_,
// **   (.,.)      (O,O)
// **   (   )      (   )
// **   -"-"---dwb--"-"---dwb-
// )",
R"(

**                    /|_
**                   /   |_
**                  /     /
**                 /      >
**                (      >
**               /      /
**              /     /
**             /      /
**          __/      \_____
**         /'             |
**          /     /-\     /
**         /      /  \--/
**        /     /
**       /      /  
**      (      >
**     /      >
**    /     _|
**   /  __/
**  /_/
)",
R"(

**                     ____
**                    / " -\
**                   /    \
**        ///////////^^^^^^\\\\\\\\\\\
**       ///////////        \\\\\\\\\\\
**      ////// \\\\\\      ////// \\\\\\
**     /////       \\      //       \\\\\
**    ////          //    \\          \\\\
**   ///          \|/ /||\ \|/          \\\
**  //             | //||\\ |             \\
** /                 ^^^^^^                 \
)"};
int main(int argc, char *argv[]) {
    srand(time(0));
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " input_file.cpp" << std::endl;
        return 1;
    }
    char author[] = "Abhijeet Adarsh";
    char *fileName = argv[1];
    preprocessorRunner(fileName);

    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the time to a string representation
    char timeString[100];
    char dateString[100];
    std::strftime(timeString, sizeof(timeString), "%H:%M:%S", std::localtime(&currentTime));
    char message[10000];
    std::strftime(dateString, sizeof(dateString), "%Y-%m-%d", std::localtime(&currentTime));
    int sz = ascii_arts.size();
    snprintf(message, sizeof(message), "/*\n** Author : %s\n** Question : %s\n** Date : %s\n** Time : %s%s*/\n#include <bits/stdc++.h>\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n", author, fileName, dateString, timeString, ascii_arts[rand() % sz].data());

    modifyFiles(".LB6hNm82#j.cpp", ".XTqXRj#15!.cpp", message);
    blankLineRemover(".LB6hNm82#j.cpp", "__final__.cpp");

    if (std::remove(".LB6hNm82#j.cpp") != 0) {
        std::perror("Error deleting the file");
        return 1;
    }
    return 0;
}
