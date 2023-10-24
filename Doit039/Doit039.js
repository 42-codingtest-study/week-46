//문제: Doit039
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    // const CHE = Array.from({ length: 1000001 }, () => true);
    // CHE[0] = false;
    // CHE[1] = false;
    // for (let i = 2; i < 1000; i++) {
    //     if (CHE[i]) {
    //         for (let div = i * 2; div <= 1000000; div += i) {
    //             //배수들 0으로 바꿔
    //             CHE[div] = false;
    //         }
    //     }
    // }
    const CHECK_SOSU = (n) => {
        if (n === 1) return false;
        else if (n === 2) return true;
        else {
            for (let i = 2; i * i <= n; i++) {
                if (n % i === 0) return false;
            }
            return true;
        }
    };
    let num = +input[0]; //"31"
    while (true) {
        let n = num + "";
        let u = [...n].reverse().join(""); // 로꾸꺼 수
        if (n === u && CHECK_SOSU(num)) {
            //같고 소수면
            console.log(num); //출력하고
            break; //끝~
        }
        num++;
    }
}
