FROM trzeci/emscripten:sdk-tag-1.38.32-64bit as build

COPY ./src /src/

RUN mkdir -p /dist/
WORKDIR /dist/

# 1. simple example
RUN emcc /src/*.cpp -o index.html

# 2. bind C++ to existing frontend
RUN emcc /src/fibonacci.cpp -o app.js -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]'

FROM nginx:1.17.0-alpine

COPY --from=build /dist/ /usr/share/nginx/html/
COPY ./app/ /usr/share/nginx/html/
