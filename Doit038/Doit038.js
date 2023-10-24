//문제: Doit038
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인: 거의 소수 구하기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const ERATOS = (n) => {
        const CHE = Array.from({ length: 10000001 }, () => true);
        CHE[0] = false;
        CHE[1] = false;
        for (let i = 2; i < 3163; i++) {
            if (CHE[i]) {
                for (let div = i * 2; div <= 10000002; div += i) {
                    //배수들 0으로 바꿔
                    CHE[div] = false;
                }
            }
        }
        //일단 소수구함
        // 소수 제곱수면 2로바꿈
        return CHE;
    }; //에토체 만들기
    const [N, M] = input[0].split(" ").map(Number);
    let answer = 0;
    const SOSU_M = ERATOS(M);
    for (let i = 1; i <= 10000001; i++) {
        if (SOSU_M[i]) {
            let div = i * i;
            while (div <= M) {
                if (div >= N) answer++;
                div *= i;
            }
        }
    }

    console.log(answer);
}
