#include "objLoader.h"
#include<fstream>
#include<iostream>
#include<cstdlib>

using namespace std;
double change_size = 20;

objLoader::objLoader(string filename)
{
    cout << filename << endl;
    string line;
    fstream f;
    f.open(filename, ios::in);

    if(!f)
    {
        system("chdir");
        cout << "Something Went Wrong When Opening Objfiles" << endl;
    }
    
    while(!f.eof())
    {
        getline(f, line);
        // cout << line << endl;
        vector<string> parameters;
        string tailMark = " ";
        string ans = "";
        line = line.append(tailMark);
        for (int i = 0; i < (int)line.length(); i++)
        {
            char ch = line[i];
            if( ch!= ' ')
            {
                ans += ch;
            }
            else
            {
                if (ans != "")
                {
                    parameters.push_back(ans);
                }
                ans = "";
            }
        }
        if (parameters.size() == 4 )
        {
            //点的信息
            if(parameters[0] == "v")
            {
                vector<GLfloat> Point;
                
                for (int i = 1; i < 4;++i)
                {
                    GLfloat xyz = atof(parameters[i].c_str());
                    Point.push_back(xyz / change_size);
                }
                this->vSets.push_back(Point);
            }
            else if (parameters[0] == "vt")
            {
                vector<GLfloat> Texture;
                for (int i = 1; i < 4;++i)
                {
                    GLfloat xyz = atof(parameters[i].c_str());
                    Texture.push_back(xyz / change_size);
                }
                this->vtSets.push_back(Texture);
            }
            else if(parameters[0] == "vn")
            {
                vector<GLfloat> Normal;
                for (int i = 1; i < 4;++i)
                {
                    GLfloat xyz = atof(parameters[i].c_str());
                    Normal.push_back(xyz / change_size);
                }
                this->vnSets.push_back(Normal);
            }
            else if(parameters[0] == "f")
            {
                vector<GLint> vIndexSets;
                vector<GLint> vtIndexSets;
                vector<GLint> vnIndexSets;
                for (int i = 1; i < 4;++i)
                {
                    string x = parameters[i];
                    string ans = "";
                    int flag = 0;
                    for (int j = 0; j < (int)x.length();++j)
                    {
                        char ch = x[j];
                        if(ch != '/')
                        {
                            if (j < (int) x.length() -1 )
                            {
                                ans += ch;
                            }
                            else
                            {
                                GLint index = atof(ans.c_str());
                                index--;
                                vnIndexSets.push_back(index);
                                ans = "";
                            }
                        }
                        else if (ch == '/')
                        {
                            if(flag == 0)
                            {
                                GLint index = atof(ans.c_str());
                                index--;
                                vIndexSets.push_back(index);
                                ans = "";
                                flag++;
                            }
                            else if (flag == 1)
                            {
                                GLint index = atof(ans.c_str());
                                index--;
                                vtIndexSets.push_back(index);
                                ans = "";
                                flag++;
                            }
                        }
                    }
                }
                this->fvSets.push_back(vIndexSets);
                this->fvtSets.push_back(vtIndexSets);
                this->fvnSets.push_back(vnIndexSets);
            }
        }
    }
    //cout << this->fvSets.size() << endl;
    f.close();
}

void objLoader::Draw()
{
    
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 1.0);
    
    for (int i = 0; i < (int) this->fvSets.size();++i)
    {
        if((this->fvSets[i]).size() != 3 ||(this->fvtSets[i]).size() !=3 || (this->fvnSets[i]).size() !=3)
        {
            cout << "the fvSetsets_Size is not correct" << endl;
			cout << (this->fvSets[i]).size() << ' ' << (this->fvtSets[i]).size() << ' ' << (this->fvnSets[i]).size() << endl;
        }
        else
        {
            GLint firstVertexIndex = (fvSets[i])[0];
            GLint secondVertexIndex = (fvSets[i])[1];
            GLint thirdVertexIndex = (fvSets[i])[2];

            GLint firstTextureIndex = (fvtSets[i])[0];
            GLint secondTextureIndex = (fvtSets[i])[1];
            GLint thirdTextureIndex = (fvtSets[i])[2];

            GLint firstNormalIndex = (fvnSets[i])[0];
            GLint secondNormalIndex = (fvnSets[i])[1];
            GLint thirdNormalIndex = (fvnSets[i])[2];

            glNormal3f((vnSets[firstVertexIndex])[0], (vnSets[firstVertexIndex])[1], (vnSets[firstVertexIndex])[2]);
			glTexCoord3f((vtSets[firstVertexIndex])[0], (vtSets[firstVertexIndex])[1], (vtSets[firstVertexIndex])[2]);
			glVertex3f((vSets[firstVertexIndex])[0], (vSets[firstVertexIndex])[1], (vSets[firstVertexIndex])[2]);

			glNormal3f((vnSets[secondVertexIndex])[0], (vnSets[secondVertexIndex])[1], (vnSets[secondVertexIndex])[2]);
			glTexCoord3f((vtSets[secondVertexIndex])[0], (vtSets[secondVertexIndex])[1], (vtSets[secondVertexIndex])[2]);
			glVertex3f((vSets[secondVertexIndex])[0], (vSets[secondVertexIndex])[1], (vSets[secondVertexIndex])[2]);

			glNormal3f((vnSets[thirdVertexIndex])[0], (vnSets[thirdVertexIndex])[1], (vnSets[thirdVertexIndex])[2]);
			glTexCoord3f((vtSets[thirdVertexIndex])[0], (vtSets[thirdVertexIndex])[1], (vtSets[thirdVertexIndex])[2]);
			glVertex3f((vSets[thirdVertexIndex])[0], (vSets[thirdVertexIndex])[1], (vSets[thirdVertexIndex])[2]);
        }
    }
    glEnd();
}