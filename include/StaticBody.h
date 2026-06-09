#ifndef README_MD_STATICBODY_H
#define README_MD_STATICBODY_H


class StaticBody {
public:
    StaticBody();
    explicit StaticBody(int transform_index);
    int transform_index{};
};


#endif //README_MD_STATICBODY_H