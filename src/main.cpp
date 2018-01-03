#include <sjc.h>
#include <boost/process.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;
namespace bp = boost::process;
           
#ifdef YYDEBUG
extern int yydebug;
#endif

void __fail(const char* s) {
    printf("%s\n", s);
    exit(-1);
}

void createProject(string typeName) {
    auto fullPath = fs::current_path();
    auto workspaceFolderBasename = fullPath.filename().string();

    printf("Creating new %s project for app %s\n", typeName.c_str(), workspaceFolderBasename.c_str());

    fs::create_directory(".vscode");

    ofstream streamTasks;
    streamTasks.open(".vscode/tasks.json");
    streamTasks << 
R"({
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "sjc",
            "type": "shell",
            "command": "../sj/sjc main.sj --no-lines",
            "promptOnClose": true,
            "group": "build",
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": true,
                "panel": "shared"
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "gcc",
            "type": "shell",
            "command": "gcc -g main.c -I. -I/usr/local/include/freetype2 -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2main -lpng16 -lfreetype -o ${workspaceFolderBasename} -framework OpenGL",
            "windows": {
                "command": "gcc -g main.c -I. -I/mingw64/include/freetype2 -I/mingw64/include/SDL2 -L/mingw64/lib -Dmain=SDL_main -DWIN32 -lmingw32 -lSDL2main -lSDL2 -llibpng16 -lopengl32 -lfreetype -lglew32 -o ${workspaceFolderBasename}.exe"                
            },
            "dependsOn" : "sjc",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "emcc",
            "type": "shell",
            "command": "emcc -g main.c -o ${workspaceFolderBasename}.html -I. -s USE_SDL=2 -s USE_FREETYPE=1 -s USE_LIBPNG=1 -s USE_WEBGL2=1 --preload-file assets --preload-file shaders",
            "dependsOn" : "sjc",
            "group": "build",
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "emrun",
            "type": "shell",
            "command": "emcc -g main.c -o ${workspaceFolderBasename}.html -I. -s USE_SDL=2 -s USE_FREETYPE=1 -s USE_LIBPNG=1 -s USE_WEBGL2=1 --preload-file assets --preload-file shaders --emrun && emrun ${workspaceFolderBasename}.html",
            "dependsOn" : "sjc",
            "group": "build",
            "problemMatcher": [
                "$gcc"
            ]
        }
    ]
})";

    ofstream streamSettings;
    streamSettings.open(".vscode/settings.json");
    streamSettings << 
R"({
    "terminal.integrated.shell.windows": "C:\\msys64\\usr\\bin\\bash.exe",
    "terminal.integrated.shellArgs.windows": [
        "--login",
        "-i", 
    ],
    "terminal.integrated.env.windows": {
        "CHERE_INVOKING": "1",
        "MSYSTEM": "MINGW64",
    },
})";

    ofstream streamLaunch;
    streamLaunch.open(".vscode/launch.json");
    streamLaunch << 
R"({
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/${workspaceFolderBasename}",
            "windows": {
                "program": "${workspaceFolder}/${workspaceFolderBasename}.exe",                
                "miDebuggerPath": "C:/msys64/mingw64/bin/gdb.exe"
            },
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/local/bin/gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "gcc"
        }
    ]
})";

    auto contents = string(R"(main.c
{workspaceFolderBasename}.exe
{workspaceFolderBasename}
{workspaceFolderBasename}.dSYM/
)");

    boost::replace_all(contents, "{workspaceFolderBasename}", workspaceFolderBasename);

    ofstream streamGitIgnore;
    streamGitIgnore.open(".gitignore");
    streamGitIgnore << contents;

    ofstream streamMain;
    streamMain.open("main.sj");
    streamMain << 
R"(console.writeLine("hello world"))";

    // std::string exec = "bjam"; 

    // std::vector<std::string> args; 
    // args.push_back("--version"); 

    // bp::context ctx; 
    // ctx.stdout_behavior = bp::capture_stream(); 

    // vector<string> args;
    // args.push_back("submodule");
    // args.push_back("add");
    // args.push_back("-b");
    // args.push_back("master");
    // args.push_back("");
    // bp::child c = bp::launch("git", args, ctx); 

    // bp::pistream &is = c.get_stdout(); 
    // std::string line; 
    // while (std::getline(is, line)) 
    //     std::cout << line << std::endl; 
        
    // c.wait();

    fs::create_directory("lib");
    bp::system("git submodule add -b master https://github.com/justinmann/sj-lib-common.git", bp::std_out > stdout, bp::std_err > stderr, bp::std_in < stdin, bp::start_dir = "lib");
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
        ("new-project", po::value<string>(), "ui or console")
        ("skip-library-pull", "skip updating the submodules for libraries")
        ("skip-library-copy", "skip copying assets from the libraries")
#ifdef YYDEBUG
        ("debug-parser", "add extra debug logging to detect memory leaks")
#endif
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

    if (vm.count("help") || (!vm.count("sj-file") && !vm.count("new-project"))) {
        cout << visible << "\n";
        return 1;
    }

    auto libraryPull = vm.count("skip-library-pull") == 0;
    auto libraryCopy = vm.count("skip-library-copy") == 0;
    bool outputLines = vm.count("no-lines") == 0;
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
    auto sjFilename = vm.count("sj-file") ? vm["sj-file"].as<string>() : string();
    auto newProject = vm.count("new-project") ? vm["new-project"].as<string>() : string();

    if (sjFilename.size() > 0) {
        auto path = fs::path(sjFilename);
        if (cFilename.size() == 0) {
            cFilename = fs::change_extension(path, ".c").string();
        }

        if (outputDebug) {
            if (debugFilename.size() == 0) {
                debugFilename = fs::change_extension(path, ".debug").string();
            }
        }

        Compiler compiler(outputLines, outputVSErrors, outputDebugLeaks, outputFree, libraryPull, libraryCopy);
        compiler.transpile(path.string(), cFilename, errorFilename, debugFilename);
    }

    if (newProject.size() > 0) {
        createProject(newProject);
    }

    return 0;
}
