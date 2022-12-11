extern "C"
{
    extern const char* GIT_TAG;
    extern const char* GIT_REV;
}

const char* git_version()
{
    return GIT_TAG;
}

const char* git_revision()
{
    return GIT_REV;
}

