# Integrating the vcpkg Toolchain with the Project

1. Open CLion.

2. Go to `File > Settings > Build, Execution, Deployment > CMake`.

3. In the `CMake options` field, add the following line:

    ```
    -DCMAKE_TOOLCHAIN_FILE=<vcpkg_dir>/scripts/buildsystems/vcpkg.cmake
    ```

   Replace `<vcpkg_dir>` with the path to your vcpkg installation directory.
