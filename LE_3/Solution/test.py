import subprocess

def run_cpp_file():
    # Compile the C++ code
    cpp_filename = 'bst_test.cpp'
    compile_process = subprocess.run(["g++", cpp_filename, "-o", "temp_executable"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Check for compilation errors
    if compile_process.returncode != 0:
        print("Compilation error:")
        print(compile_process.stderr)
        return

    # Run the compiled executable
    run_process = subprocess.run(["./temp_executable"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Print the output and error
    print("Output:")
    print(run_process.stdout)

    if(run_process.stderr):
        print("Error:")
        print(run_process.stderr)

run_cpp_file()
