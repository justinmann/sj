#include <sjc.h>

namespace fs = boost::filesystem;
namespace po = boost::program_options;
           
#ifdef YYDEBUG
extern int yydebug;
#endif

void __fail(const char* s) {
    printf("%s\n", s);
    exit(-1);
}

int main(int argc, char **argv) {
    po::options_description generic_options("Generic options");
    generic_options.add_options()
        ("help", "show helper")
        ;

    po::options_description config_options("Configuration");
    config_options.add_options()
        ("no-lines", "do not output #lineno directive")
        ("vs-errors", "output vs compatible error format")
        ("debug", "output debug files")
        ("debug-file", po::value<string>(), "filename for debug output")
        ("debug-leaks", "add extra debug logging to detect memory leaks")
        ("debug-no-free", "do not free any objects, only use this when debugging a leak")
        ("c-file", po::value<string>(), "filename for c output")
        ("error-file", po::value<string>(), "filename for error output")
        ;

#ifdef YYDEBUG
        ("debug-parser", "add extra debug logging to detect memory leaks")
        // TODO: ("wasm", "output wasm (not supported yet)")
        // TODO: ("app", "output app for current system (not supported yet)")
#endif

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
    // TODO: bool outputWasm = vm.count("wasm");
    // TODO: bool outputApp = vm.count("app");
    bool outputDebug = vm.count("debug");
    bool outputVSErrors = vm.count("vs-errors");
    bool outputDebugLeaks = vm.count("debug-leaks");
    bool outputFree = vm.count("debug-no-free") == 0;
#ifdef YYDEBUG
    yydebug = vm.count("debug-parser"); // use this to trigger the verbose debug output from bison
#endif
    auto cFilename = vm.count("c-file") ? vm["c-file"].as<string>() : string();
    auto debugFilename = vm.count("debug-file") ? vm["debug-file"].as<string>() : string();
    auto errorFilename = vm.count("error-file") ? vm["error-file"].as<string>() : string();
    auto sjFilename = vm["sj-file"].as<string>();

    auto path = fs::path(sjFilename);
    if (cFilename.size() == 0) {
        cFilename = fs::change_extension(path, ".c").string();
    }

    if (outputDebug) {
        if (debugFilename.size() == 0) {
            debugFilename = fs::change_extension(path, ".debug").string();
        }
    }

    Compiler compiler(outputLines, outputVSErrors, outputDebugLeaks, outputFree);
    compiler.transpile(path.string(), cFilename, errorFilename, debugFilename);

    return 0;
}