#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

class SegmentTree
{
    typedef int elem_t;
    typedef long long sum_t;

    std::vector<sum_t> segm; // holds segment tree
    size_t orig_size; // original vector size

    // qs - query start pos (inclusive)
    // qe - query end pos (inclusive)
    // ts - current start pos at pos in segm (inclusive)
    // ts - current end pos at pos in segm (inclusive)
    // pos - current pos in segm
    sum_t query2(const std::vector<sum_t> &segm, size_t qs, size_t qe, size_t ts, size_t te, size_t pos)
    {
        if (qs > te || qe < ts) // no overlap
        {
            return 0;
        }
        else if (qs <= ts && qe >= te) // total overlap
        {
            return segm[pos];
        }
        else // partial overlap
        {
            size_t tmid = (ts + te) / 2;
            return std::max(query2(segm, qs, qe, ts, tmid, 2*pos + 1), query2(segm, qs, qe, tmid + 1, te, 2*pos + 2));
        }
    }

    // s and e - current range (both inclusive)
    // pos - current pos in segm
    void fill_segm(const std::vector<elem_t> &vec, std::vector<sum_t> &segm, size_t s, size_t e, size_t pos)
    {
        if (s == e)
        {
            segm[pos] = vec[s];
        }
        else
        {
            size_t mid = (s + e) / 2; // includes mid if odd
            size_t left_ch_pos = pos * 2 + 1;
            size_t right_ch_pos = pos * 2 + 2;
            fill_segm(vec, segm, s, mid, left_ch_pos); // left child, left half
            fill_segm(vec, segm, mid + 1, e, right_ch_pos); // right child, right half
            segm[pos] = std::max(segm[left_ch_pos], segm[right_ch_pos]);
        }
    }

public:

    SegmentTree(const std::vector<elem_t> &vec)
    {
        int last_lvl_len = 1;
        while (last_lvl_len < vec.size()) last_lvl_len *= 2;
        segm.resize(last_lvl_len * 2 - 1, -1);

        fill_segm(vec, segm, 0, vec.size() - 1, 0);
        orig_size = vec.size();
    }

    // qs - query start pos (inclusive)
    // qe - query end pos (inclusive)
    sum_t query(size_t s, size_t e)
    {
        if (!(e < orig_size && s <= e)) return 0;
        return query2(segm, s, e, 0, orig_size - 1, 0);
    }
};

std::vector<int> solve(SegmentTree &st, int n, int k)
{
    std::vector<int> ans(n - k + 1, 0);

    for (int i = 0; i < ans.size(); ++i)
    {
        ans[i] = st.query(i, i + k - 1);
    }

    return ans;
}

int main()
{
    int n, k;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) std::cin >> vec[i];
    std::cin >> k;

    SegmentTree st{vec};

    for (auto a : solve(st, n, k)) std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}
