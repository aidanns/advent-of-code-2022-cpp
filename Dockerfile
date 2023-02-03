FROM advent-of-code-2022/builder as builder

# Add all the files we need to build from to the build container.
COPY . /project

# Run the build.
RUN cmake -DCMAKE_BUILD_TYPE=Release -S /project -B /build && \
    cmake --build /build -- -j 8

FROM scratch

# Copy the built binary from the builder container.
COPY --from=builder /build/advent_of_code_2022_cpp /advent_of_code_2022_cpp

CMD ["/advent_of_code_2022_cpp"]

