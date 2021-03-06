// counter-clockwise order
template<typename T>
vector<complex<T>> convex_hull(vector<complex<T>> pts) {
    sort(begin(pts), end(pts), lex_cmp<T>), pts.erase(unique(begin(pts), end(pts)), end(pts));
    if (size(pts) <= 1) return pts;
    vector<complex<T>> upper(size(pts)), lower(size(pts));
    int k = 0, l = 0;
    for (auto p : pts) {
        while (k > 1 && not cw(upper[k - 2], upper[k - 1], p)) --k;
        while (l > 1 && not ccw(lower[l - 2], lower[l - 1], p)) --l;
        upper[k++] = lower[l++] = p;
    }
    upper.resize(k - 1), lower.resize(l);
    reverse(begin(upper), end(upper));
    lower.insert(end(lower), begin(upper), end(upper) - 1);
    return lower;
}
