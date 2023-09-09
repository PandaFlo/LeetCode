// Define a structure for pairs (value, index)
struct Pair {
    int value;
    int index;
};

// Function to compare two pairs based on their values
int comparePairs(const void* a, const void* b) {
    return ((struct Pair*)a)->value - ((struct Pair*)b)->value;
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    int n = costsSize;

    // Create arrays of pairs for front and back candidates
    struct Pair* fr = (struct Pair*)malloc(sizeof(struct Pair) * candidates);
    struct Pair* bk = (struct Pair*)malloc(sizeof(struct Pair) * candidates);

    long long s = 0;
    int e = n - 1;

    long long res = 0;

    long long fcnt, bcnt;
    fcnt = bcnt = candidates;

    while (k--) {
        // Fill the front candidates array
        while (s <= e && fcnt > 0) {
            fr[fcnt - 1].value = costs[s];
            fr[fcnt - 1].index = s;
            s++;
            fcnt--;
        }

        // Fill the back candidates array
        while (e >= s && bcnt > 0) {
            bk[bcnt - 1].value = costs[e];
            bk[bcnt - 1].index = e;
            e--;
            bcnt--;
        }

        // Sort the front candidates array in ascending order of values
        qsort(fr + fcnt, candidates - fcnt, sizeof(struct Pair), comparePairs);

        // Sort the back candidates array in ascending order of values
        qsort(bk + bcnt, candidates - bcnt, sizeof(struct Pair), comparePairs);

        long long v1, v2, i1, i2;
        v1 = v2 = LLONG_MAX;
        i1 = i2 = -1;

        if (fcnt < candidates) {
            v1 = fr[fcnt].value;
            i1 = fr[fcnt].index;
        }

        if (bcnt < candidates) {
            v2 = bk[bcnt].value;
            i2 = bk[bcnt].index;
        }

        if (i1 == i2) {
            v2 = INT_MAX;
            bcnt++;
        }

        if (v1 <= v2) {
            res += v1;
            fcnt++;
        } else {
            res += v2;
            bcnt++;
        }
    }

    // Clean up allocated memory
    free(fr);
    free(bk);

    return res;
}