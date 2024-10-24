cd /start
./remove_all_running_containers.sh
./build_all_docker_images.sh
docker-compose up -d

