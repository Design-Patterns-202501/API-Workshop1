FROM python:3

WORKDIR /app 

COPY . .

RUN apt update
RUN pip install --upgrade pip
RUN pip install conan
RUN apt install -y cmake

RUN conan profile detect

RUN conan install . --output-folder=build --build=missing

RUN cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

EXPOSE 3000

CMD ["./build/server"]
