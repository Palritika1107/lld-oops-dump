#include<bits/stdc++.h>
using namespace std;


// In C++, declaring a static member inside a class only declares it. It does not allocate memory for it. The compiler expects you to define it outside the class in a global scope so memory can be allocated for it.

// What Happens if It's Not static
// If treeTypeMap is not static:

// Every TreeFactory instance would have its own separate treeTypeMap, so you would lose the benefit of reusing TreeType objects.
// Duplicate TreeType objects would be created for the same combination of name, color, and texture, leading to memory inefficiency.

//treeTypeMap is static : because i want all instances to share same map,
//treeTypeMap is private : because i only want getTreeType method to modify it 

class TreeType{

    string name;
    string color;
    string texture;

    public:

    TreeType(string name,string color,string texture):name(name),color(color),texture(texture){}

    void plant(int x,int y){

        cout<<"tree planted at: "<<x<<" "<<y;

    }

};

class Tree{
    int x;
    int y;
    shared_ptr<TreeType> treetype;

    public:
    Tree(int x,int y,shared_ptr<TreeType> treetype):x(x),y(y),treetype(treetype){}

    void plant(){
        treetype->plant(x,y);
    }
};

class TreeFactory{
    
    static unordered_map<string,shared_ptr<TreeType>>treeTypeMap;

    public:

    static shared_ptr<TreeType> getTreeType(string name,string color,string texture){
        if(treeTypeMap.find(name) == treeTypeMap.end()){
            auto type = make_shared<TreeType>(name,color,texture);
            treeTypeMap[name] = type;
        }
        return treeTypeMap[name];

    }
};



// Define the static member
unordered_map<string, shared_ptr<TreeType>> TreeFactory::treeTypeMap;

class Forest{

    vector<shared_ptr<Tree>>trees;

    public:

    shared_ptr<Tree> createTree(string name,string color,string texture,int x,int y){

        auto treetype = TreeFactory::getTreeType(name,color,texture);
        auto treePtr =  make_shared<Tree>(x,y,treetype);
        trees.push_back(treePtr);
        return treePtr;

    }

    void plantTrees(){

        for(auto tree : trees){
            tree->plant();
        }

    }


};

int main(){

    Forest forestObj;

    shared_ptr<Tree> tree1 = forestObj.createTree("pine" , "green" ,"rough",2,3);
    shared_ptr<Tree> tree2 = forestObj.createTree("pine" , "green" ,"rough",3,3);
    // tree1->plant();
    forestObj.plantTrees();




    return 0;
}
