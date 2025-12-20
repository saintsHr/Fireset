# Contributing to This Engine

Thank you for your interest in contributing! Please follow these guidelines:

## 1. Workflow (Required)
- **Do NOT work directly on the `main` branch.**
- Always create a new branch from `main` in your fork.
- Branch names must include a **type prefix**, between square brackets and a **short, commit-style description**:

[fix] short description
[feature] short description
[doc] short description
[refactor] shortdescription


- Focus on **one feature, bugfix, or improvement per PR**.
- Keep changes small, scoped, and easy to review.

The `main` branch is protected and must remain **stable and buildable** at all times.

## 2. Code Guidelines
- Keep code clean, readable, and consistent with the existing style.
- Avoid breaking existing functionality.
- Platform-specific code must stay within the appropriate platform layer (Windows/Linux).

## 3. Documentation
- Update Doxygen comments for any new or modified functions.
- Update examples or the README if your changes affect usage or behavior.

## 4. Testing
- Test your changes locally before submitting.
- Ensure the project builds on **Windows and Linux**.
- Existing examples or test programs must still compile and run.

## 5. Pull Request
- Push your branch to your fork.
- Open a PR **into the `main` branch** of the official repository.
- Clearly describe:
- What the change does
- Why it’s needed
- Any trade-offs or limitations
- Link related issues if applicable.

> Following these rules helps keep the engine stable and maintainable.  
> Not all PRs will be accepted — design consistency and long-term maintainability come first.
