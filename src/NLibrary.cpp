#include <sjc.h>
#include <boost/process.hpp>

namespace fs = boost::filesystem;
namespace bp = boost::process;

bool copyDir(fs::path const & source, fs::path const & destination) {
    try {
        // Check whether the function call is valid
        if(
            !fs::exists(source) ||
            !fs::is_directory(source)
        ) {
            std::cerr << "Source directory " << source.string()
                << " does not exist or is not a directory." << '\n';
            return false;
        }

        if(fs::exists(destination)) {
            std::cerr << "Destination directory " << destination.string()
                << " already exists." << '\n';
            return false;
        }
        // Create the destination directory
        if(!fs::create_directory(destination)) {
            std::cerr << "Unable to create destination directory"
                << destination.string() << '\n';
            return false;
        }
    } catch(fs::filesystem_error const & e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    // Iterate through the source directory
    for(
        fs::directory_iterator file(source);
        file != fs::directory_iterator(); ++file
    ) {
        try {
            fs::path current(file->path());
            if(fs::is_directory(current)) {
                // Found directory: Recursion
                if(!copyDir(
                        current,
                        destination / current.filename()
                    )) {
                    return false;
                }
            } else {
                // Found file: Copy
                fs::copy_file(
                    current,
                    destination / current.filename()
                );
            }
        }
        catch(fs::filesystem_error const & e) {
            std:: cerr << e.what() << '\n';
        }
    }
    return true;
}


void NLibrary::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    if (thisFunction->name != "global") {
        compiler->addError(loc, CErrorCode::IncludeOnlyInGlobal, "can only use library in the global scope");
    }
    
    auto index = fileName.find(":");
    auto branchName = fileName.substr(0, index);
    auto repoName = fileName.substr(index + 1, fileName.size() - index - 1);
    auto index2 = repoName.find_last_of("/");
    if (!boost::ends_with(repoName, ".git")) {
        compiler->addError(loc, CErrorCode::InvalidType, "url in library must be for git");
        return;
    }
    auto libName = repoName.substr(index2, repoName.size() - index2 - 4);
    auto libRootPath = compiler->rootPath / fs::path("lib");
    auto libPath = libRootPath / fs::path(libName);
    auto mainPath = libPath / fs::path("main.sj");

    if (!fs::is_directory(libPath)) {
        // If it does not exist then enlist
        stringstream command;
        command << "git submodule add -b " << branchName << " " << repoName;
        printf("In \"%s\" running: %s\n", libRootPath.string().c_str(), command.str().c_str());

        fs::create_directory(libRootPath);
        bp::system(command.str(), bp::std_out > stdout, bp::std_err > stderr, bp::std_in < stdin, bp::start_dir = libRootPath);
    }
    else if (compiler->libraryPull) {        
        // If it does exist then make sure we are using the correct branch
        stringstream command;
        command << "git checkout " << branchName;
        printf("In \"%s\" running: %s\n", libPath.string().c_str(), command.str().c_str());
        bp::system(command.str(), bp::std_out > stdout, bp::std_err > stderr, bp::std_in < stdin, bp::start_dir = libPath);

        printf("In \"%s\" running: git pull\n", libPath.string().c_str());
        bp::system("git pull", bp::std_out > stdout, bp::std_err > stderr, bp::std_in < stdin, bp::start_dir = libPath);
    }

    // Include the main.sj file
    compiler->includeFile(mainPath.string());

    // Copy assets
    if (compiler->libraryCopy) {
        if (fs::is_directory(libPath / "assets")) {
            fs::create_directory(compiler->rootPath / "assets");
            copyDir(libPath / "assets", compiler->rootPath / "assets" / libName);

            ofstream streamGitIgnore;
            streamGitIgnore.open((compiler->rootPath / "assets" / libName / ".gitignore").string());
            streamGitIgnore << "*";
        }
    }
}

void NLibrary::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
}

shared_ptr<CVar> NLibrary::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    return nullptr;
}
