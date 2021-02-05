#ifndef COM_GITHUB_AYUM_DLD_HPP
#define COM_GITHUB_AYUM_DLD_HPP

#include <string>

namespace com::github::ayum::dld {

/*
 * See
 * https://stackoverflow.com/questions/10727174/damerau-levenshtein-distance-edit-distance-with-transposition-c-implementation
 * for details
 */

namespace internal {

template <typename T>
    requires std::random_access_iterator<typename T::iterator>
size_t length(const T &t) {
    return t.end() - t.begin();
}

}  // namespace internal

template <typename T>
    requires std::random_access_iterator<typename T::iterator>
size_t damerau_levenshtein_distance(T p_string1, T p_string2) {
    using namespace internal;
    size_t l_string_length1 = length(p_string1);
    size_t l_string_length2 = length(p_string2);
    unsigned d[l_string_length1 + 1][l_string_length2 + 1];

    size_t i, j;
    unsigned l_cost;

    for (i = 0; i <= l_string_length1; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= l_string_length2; j++) {
        d[0][j] = j;
    }
    for (i = 1; i <= l_string_length1; i++) {
        for (j = 1; j <= l_string_length2; j++) {
            if (p_string1[i - 1] == p_string2[j - 1]) {
                l_cost = 0;
            } else {
                l_cost = 1;
            }
            d[i][j] =
                std::min(d[i - 1][j] + 1,                    // delete
                         std::min(d[i][j - 1] + 1,           // insert
                                  d[i - 1][j - 1] + l_cost)  // substitution
                );
            if ((i > 1) && (j > 1) && (p_string1[i - 1] == p_string2[j - 2]) &&
                (p_string1[i - 2] == p_string2[j - 1])) {
                d[i][j] = std::min(d[i][j],
                                   d[i - 2][j - 2] + l_cost  // transposition
                );
            }
        }
    }
    return d[l_string_length1][l_string_length2];
}

}  // namespace com::github::ayum::dld

#endif  // COM_GITHUB_AYUM_DLD_HPP
