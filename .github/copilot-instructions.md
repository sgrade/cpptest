<!-- Repository-level Copilot instructions for `cpptest` -->
# Quick guide for AI contributors

This repository is a collection of small, standalone C++ solutions and templates (competitive programming, puzzles, and utilities). The goal of this file is to give an AI agent immediate, practical context for making useful edits and additions.

- Top-level layout
  - `main.cpp` — trivial project entry point for smoke runs.
  - `templates/` — canonical helper snippets and idioms (IO, common algorithms, number theory, string helpers). Use these for code style and patterns.
  - `codeforces/`, `atcoder/`, `leetcode/` — collections of single-file solutions. Each file is intended to compile standalone with a modern g++ (use the current stable -std flag; see guidance below).
  - `misc/` — small utilities and experiments (e.g., `misc/http_log_parser/` has a CMake-based build).

- Build & run conventions
  - Default compile: use a modern g++ invocation like `/usr/bin/g++ -std=<LATEST_STABLE> -g <file.cpp> -o <fileDir>/a.out` as the fast local compile step (the workspace has a VS Code task `g++ build active file` that follows this pattern). Replace `<LATEST_STABLE>` with the desired standard (for example `c++20`, `c++23`, etc.).
  - Most solution files read from stdin and write to stdout. Preserve this pattern when adding new problems.
  - Avoid adding multi-file builds unless placed under `misc/` with CMake (see `misc/http_log_parser/README.md` for example).

- Code patterns and expectations
  - Solutions are single-file, minimal, and prioritized for clarity and speed. Keep includes tight (no heavy project scaffolding). Example: `leetcode/fraction-to-recurring-decimal.cpp` uses only `<string>` and `<unordered_map>`.
  - Use the current stable C++ standard where helpful, but prefer idiomatic, portable code that compiles on common judge environments. If a judge site (Codeforces, LeetCode, AtCoder) upgrades to a newer standard, prefer migrating affected solutions to that newer standard when appropriate.

  - Migration guidance: when a platform announces support for a newer C++ standard, update only the files that benefit from new language/library features. Document the change in the file header (one-line comment: migrated to c++23) and keep other files unchanged unless they also benefit.
  - IO style varies (scanf/printf vs iostream) — follow the style already used in the target folder (e.g., `codeforces/` tends to use `scanf/printf` in older files; `leetcode/` and `templates/` often use iostream/STD library types). Match the local file's style when editing.
  - For templates, prefer copy-pasting only the required portions (include, helper functions) rather than importing whole files.

- Tests and verification
  - There is no global test harness. For a quick smoke test, compile the changed file with g++ and run with representative input; use `main.cpp` or problem-specific sample inputs where available.
  - For multi-file programs under `misc/`, follow their CMake instructions (`mkdir build && cmake .. && make`).

- When to change repository structure
  - Keep new solutions as single files in the appropriate directory. Don't move many files into a new build system unless requested.
  - Add small README.md notes when behavior or required inputs are non-standard (see `misc/http_log_parser/README.md`).

- Integration points and external dependencies
  - The repo contains no external package manifests. Keep dependencies to standard C++ and the standard library.
  - If adding third-party code, vendor it adjacent to the file and document why in a one-line comment and (optionally) update a README.

- Examples to reference
  - `templates/reverse_iterator.cpp` — iterator idioms and commentary style.
  - `codeforces/1003A.cpp` — typical standalone solution using C stdio and STL helpers.
  - `misc/http_log_parser/` — example of adding a small CMake-based utility with docs and tests.

- Editing guidance for AI
  - Preserve single-file, standalone semantics. Changes should not require global rebuild or CI changes.
  - When fixing or improving a solution: add brief comments and prefer minimal diffs (fix bug or readability, include short test example in a comment if helpful).
  - When adding new solution files: include problem ID/title in a top comment and a short link (if from a public judge). Follow the directory naming convention (`leetcode/`, `codeforces/`, `atcoder/`, `misc/`).
  - Avoid changing existing IO formats. If you must, document the change in the file header and update nearby README if needed.

If anything here is unclear or you want additional project-specific rules (naming, formatting, CI), tell me which area to expand and I'll update this file. 
