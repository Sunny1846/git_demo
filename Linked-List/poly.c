#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long eval_poly(long long coeff[], int len, long long x) {
    long long res = coeff[0];
    for (int i = 1; i < len; ++i) res = res * x + coeff[i];
    return res;
}

int synthetic_divide(long long coeff[], int len, long long root, long long out[]) {
    // coeff: length len (degree = len-1), divide by (x - root)
    // out receives quotient of length len-1; returns remainder
    out[0] = coeff[0];
    for (int i = 1; i < len - 1; ++i) out[i] = coeff[i] + out[i - 1] * root;
    long long remainder = coeff[len - 1] + out[len - 2] * root;
    return (int)remainder; // remainder fits in int check; but we only test zero
}

int main(void) {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) return 0;

    long long coeff[4];
    coeff[0] = 1;
    coeff[1] = a;
    coeff[2] = b;
    coeff[3] = c;
    int len = 4; // current polynomial length (degree + 1)

    long long absC = llabs(c);
    if (absC == 0) { // handle c == 0: root 0 exists (but original problem stated c != 0)
        // we still handle it robustly
        absC = 1;
    }

    // collect divisors of c (unique)
    long long divs[1000];
    int dcount = 0;
    for (long long i = 1; i * i <= llabs(c); ++i) {
        if (llabs(c) % i == 0) {
            divs[dcount++] = i;
            if (i * i != llabs(c)) divs[dcount++] = llabs(c) / i;
        }
    }
    // include negative counterparts
    int totalCandidates = 0;
    long long cand[2000];
    for (int i = 0; i < dcount; ++i) {
        cand[totalCandidates++] = divs[i];
        cand[totalCandidates++] = -divs[i];
    }

    long long roots[3];
    int mult[3];
    int rcount = 0;

    // try each candidate root (order doesn't matter)
    for (int i = 0; i < totalCandidates && len > 1; ++i) {
        long long x = cand[i];

        // avoid duplicate root processing (if already recorded)
        int already = 0;
        for (int j = 0; j < rcount; ++j) if (roots[j] == x) { already = 1; break; }
        if (already) continue;

        int multiplicity = 0;
        // attempt repeated division while x is a root of current polynomial
        while (len > 1 && eval_poly(coeff, len, x) == 0) {
            long long quotient[4]; // max len-1 <= 3
            int rem = synthetic_divide(coeff, len, x, quotient);
            if (rem != 0) break; // should not happen since eval_poly returned 0
            // copy quotient back to coeff
            for (int k = 0; k < len - 1; ++k) coeff[k] = quotient[k];
            len = len - 1;
            multiplicity++;
            if (multiplicity > 3) break;
        }

        if (multiplicity > 0) {
            roots[rcount] = x;
            mult[rcount] = multiplicity;
            rcount++;
        }
    }

    // success only if we've reduced polynomial to constant (len == 1) and total multiplicities sum to 3
    int totalMult = 0;
    for (int i = 0; i < rcount; ++i) totalMult += mult[i];

    if (len == 1 && totalMult == 3) {
        // sort roots ascending
        for (int i = 0; i < rcount - 1; ++i)
            for (int j = i + 1; j < rcount; ++j)
                if (roots[i] > roots[j]) {
                    long long tmp = roots[i]; roots[i] = roots[j]; roots[j] = tmp;
                    int t = mult[i]; mult[i] = mult[j]; mult[j] = t;
                }
        for (int i = 0; i < rcount; ++i)
            printf("%lld %d\n", roots[i], mult[i]);
    } else {
        printf("NO SOLUTION\n");
    }

    return 0;
}
