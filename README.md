# Workshop 1 API

You can execute the server using Docker.

> [!WARNING]
> The commands include `sudo` directive, for Windows users may change.

## Build the API

```bash
sudo docker build -t cpp-server .
```

## Running the container with bind mount

Bind mount allows the container write the files into hosts filesystem. **You need Linux platform and the project builded**.

```bash
sudo docker run --mount type=bind,src="$(pwd)",target=/app -d -p 127.0.0.1:3000:3000 cpp-server
```

## Running the container in any platform

It couldn't be possible see the files writed, only using Docker Desktop in Windows.

```bash
sudo docker run -d -p 127.0.0.1:3000:3000 cpp-server
```

## Stop and delete the container

```bash
sudo docker rm $(sudo docker stop $(sudo docker ps -a -q --filter ancestor=cpp-server --format="{{.ID}}"))
```

This command will delete all the containers (Including the stopped ones) with the image itself.
