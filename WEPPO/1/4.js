function fibb_iter(n) {
    if (n === 0)
        return 0;
    if (n === 1)
        return 1;
    var f0 = 0;
    var f1 = 1;
    for (var i = 1; i < n; i++) {
        f1 = f1 + f0;
        f0 = f1 - f0;
    }
    return f1;
}

function fibb_rec(n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibb_rec(n - 1) + fibb_rec(n - 2);
}

var n = 30;
for (var i = 0; i <= n; i++) {
    console.log('n =', i);
    console.time('iter');
    iterTime = fibb_iter(i);
    console.timeEnd('iter');
    console.time('rec');
    recTime = fibb_rec(i);
    console.timeEnd('rec');
}