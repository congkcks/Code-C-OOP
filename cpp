{
    "cmd": [" C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe", "-std=c++17", "${file}",
            "-o", "${file_base_name}.exe",
            "&&", "${file_base_name}.exe<TASK.inp>TASK.out"],
    "shell":true,
    "working_dir":"$file_path",
    "selector":"source.cpp"
}