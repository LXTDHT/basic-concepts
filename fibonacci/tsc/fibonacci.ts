const N = 10; // Set the number of iterations here.

let f: number[] = []; f.push(0); f.push(1); f.push(1);

for (let i = 3; i < N; ++i) {
    f.push(f[i - 1] + f[i - 2]);
}

for (let i = 0; i < N; ++i) {
    console.log(f[i]);
}