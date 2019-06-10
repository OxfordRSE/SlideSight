#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#ifdef CXX_FILESYSTEM_IS_EXPERIMENTAL
#include <experimental/filesystem>
#define SIGHT_FILESYSTEM_NS std::experimental::filesystem
#else
#include <filesystem>
#define SIGHT_FILESYSTEM_NS std::filesystem
#endif

#endif // FILESYSTEM_HPP
