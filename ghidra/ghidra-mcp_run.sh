for i in 8091 8092 8093 8094; do
  docker rm -f ghidra-mcp-$i
done


for i in 8091 8092 8093 8094; do
  docker run -d \
    --name ghidra-mcp-$i \
    -p 127.0.0.1:$i:$i \
    -v /home/h/lineageos/device/sony/SemcCameraUI:/projects \
    -v ghidra_data_$i:/data \
    -e GHIDRA_MCP_PORT=$i \
    -e GHIDRA_MCP_AUTH_TOKEN=abc123456 \
    -e JAVA_OPTS="-Xmx4g -XX:+UseG1GC" \
    ghidra-mcp-headless:latest \
    --port $i
done