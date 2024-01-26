/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    let str1 = s;
    let str2 = t;
    let n1 = str1.length;
    let n2 = str2.length;
    if (n1 != n2) return false;
    const mp1 = new Map();
    const mp2 = new Map();
    let ans = true;


    for (let i = 0; i < n1; i++) {
        if (mp1.has(str1[i])) {
            let freq = mp1.get(str1[i]);
            mp1.set(str1[i], freq + 1);
        } else {
            mp1.set(str1[i], 1);
        }
    }


    for (let i = 0; i < n2; i++) {
        if (mp2.has(str2[i])) {
            let freq = mp2.get(str2[i]);
            mp2.set(str2[i], freq + 1);
        } else {
            mp2.set(str2[i], 1);
        }
    }


    if (mp1.size != mp2.size) return false;

    mp1.forEach(function (value, key) {

        if (mp2.has(key)) {

            if (mp2.get(key) != value) {
                ans = false;
                return ans;
            }
        } else {
            console.log(key + ':' + value);
            ans = false;
            return ans;
        }
    });

    if (!ans) return false;

    mp2.forEach(function (value, key) {

        console.log(key + '=' + value);
        if (mp1.has(key)) {

            if (mp1.get(key) != value) {
                ans = false;
                return ans;
            }

        } else {
            ans = false;
            return ans;
        }
    })


    return ans;
};