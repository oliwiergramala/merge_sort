# Contributing

## About

This file specifies the rules for contributing to this project.

## Rules

### Language

The language used in the repository should be English.\
Polish comments in the code are acceptable only on the `dev` branch.

On the `main` branch everything must be written in English.

### Commit prefixes

Use the following commit prefixes:

feature/ - for adding new features\
chore/ - for cleanup or removing unnecessary things\
doc/ - for adding or updating documentation\
fix/ - for bug fixes

### Branches

**main**\
The branch that should always contain stable and working code.

**dev**\
The development branch where new features are created. Code here does
not always have to be fully working.

**commit-prefix/feature-name**\
Branches created for working on a single feature or change.

### Development workflow

The general workflow is:

When you start working on something, create a branch based on the `dev`
branch for the specific feature you want to implement.

Example:

If you want to add a new feature to an algorithm (for example dynamic
input array length instead of fixed length):

Create a branch from `dev`:

feature/add_dynamic_length_for_algorithm_input_array

Work on this branch and push your changes regularly using commits to
this feature branch.

When you finish your work, create a Pull Request to merge your changes
into the `dev` branch.

### File naming

File names should be clear and understandable for people who may not
specialize in a specific programming language.

### Repository files

Only source files should be stored in the repository.\
Binary files and build artifacts should not be committed.

Make sure to create a proper `.gitignore` file for your project.
