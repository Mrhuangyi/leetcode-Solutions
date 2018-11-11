/*

给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

边界情况:

你是否考虑了 路径 = "/../" 的情况？
在这种情况下，你需返回 "/" 。
此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        for(auto i = path.begin(); i != path.end();) {
            i++;
            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);
            if(!dir.empty() && dir != ".") {
                if(dir == "..") {
                    if(!dirs.empty()) {
                        dirs.pop_back();
                    }
                } else {
                    dirs.push_back(dir);
                }
            }
            i = j;
        }
        stringstream out;
        if(dirs.empty()) {
            out << "/";
        } else {
            for(auto dir : dirs) {
                out << '/' << dir;
            }
        }
        return out.str();
    }
};
