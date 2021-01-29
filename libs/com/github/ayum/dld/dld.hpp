#ifndef COM_GITHUB_AYUM_DLD_HPP
#define COM_GITHUB_AYUM_DLD_HPP

#include <string>

namespace com::github::ayum::dld {

size_t damerau_levenshtein_distance(std::string p_string1,
                                    std::string p_string2);

}  // namespace com::github::ayum::dld

#endif  // COM_GITHUB_AYUM_DLD_HPP
