# Workshop 1 API

You can execute the server using Docker.

> [!WARNING]
> The commands include `sudo` directive, for Windows users may change.

## Build the API

```bash
sudo docker build -t cpp-server .
```

## Running the container

```bash
sudo docker run --mount type=bind,src="$(pwd)",target=/app -d -p 127.0.0.1:3000:3000 cpp-server
```

## Stop and delete the container

```bash
sudo docker rm $(sudo docker stop $(sudo docker ps -a -q --filter ancestor=cpp-server --format="{{.ID}}"))
```

This command will delete all the containers (Including the stopped ones) with the image itself.
