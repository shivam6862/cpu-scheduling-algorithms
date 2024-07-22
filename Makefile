setup:
	sh ./scripts/setup.sh

build:
	DOCKER_TARGET=local docker compose build

up:
	DOCKER_TARGET=local docker compose up

down:
	docker compose down

dev_build:
	DOCKER_TARGET=production docker compose build --no-cache