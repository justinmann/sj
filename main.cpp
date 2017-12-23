#include "node/Node.h"
#include <string.h>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;
           
int main(int argc, char **argv) {
    po::options_description generic_options("Generic options");
    generic_options.add_options()
        ("help", "show help")
        ;

    po::options_description config_options("Configuration");
    config_options.add_options()
        ("no-lines", "do not output #lineno directive")
        ("wasm", "output wasm (not supported yet)")
        ("app", "output app for current system (not supported yet)")
        ("debug", "output debug files")
        ("c-file", po::value<string>(), "filename for c output - defaults to sj file with extension changed to c")
        ;

    po::options_description hidden_options("Hidden options");
    hidden_options.add_options()
        ("sj-file", "file to compile")
        ;

    po::options_description cmdline_options;
    cmdline_options.add(generic_options).add(config_options).add(hidden_options);

    po::options_description config_file_options;
    config_file_options.add(config_options).add(hidden_options);

    po::options_description visible("Allowed options");
    visible.add(generic_options).add(config_options);

    po::positional_options_description p;
    p.add("sj-file", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
        options(cmdline_options).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help") || !vm.count("sj-file")) {
        cout << visible << "\n";
        return 1;
    }

    bool outputLines = vm.count("no-lines") == 0;
    bool outputWasm = vm.count("wasm");
    bool outputApp = vm.count("app");
    bool outputDebug = vm.count("debug");
    auto cFilename = vm.count("c-file") ? vm["c-file"].as<string>() : string();
    auto sjFilename = vm["sj-file"].as<string>();

    auto path = fs::path(sjFilename);
    if (cFilename.size() == 0) {
        cFilename = fs::change_extension(path, ".c").string();
    }
    ofstream cStream;
    cStream.open(cFilename.c_str());

    ofstream* debugStream = nullptr;
    ofstream debug;
    if (outputDebug) {
        auto debugFileName = fs::change_extension(path, ".debug");
        debug.open(debugFileName.c_str());
        debugStream = &debug;
    }

    Compiler compiler(outputLines);
    compiler.transpile(path.string(), cStream, cerr, debugStream);

    return 0;
}
