#include <iostream> 

using namespace std;


class sinner{
    public:
        bool targeted;
        long long int clawlen;
};
class arrow{
    public:
        int left;
        int right;
        arrow (int left, int right){
            this->left = left;
            this->right = right;
        }
        arrow join(arrow arw){
            if (arw.left >= this->left && arw.right <= this->right) return *this; //arw is a subset of this
            else if(arw.left < this->left && arw.right<= this->right && arw.right >= this->left) //arw is longer left-wise
            {
                this->left = arw.left;
                return *this;
            }
            else if(arw.left >= this->left && arw.left <= this->right && arw.right > this->right) //arw is longer right-wise
            {
                this -> right = arw.right;
                return *this;
            }
            else if (arw.left < this->left && arw.right > this->right) return arw; // if arw is longer than this on both ends
            return arw; //returns the arrow if they are mutually exclusive
        }
        bool isSubsetOf(arrow arw){
            return ((this->left >= arw.left) && (this->right <= arw.right));
        }
};
void printSinners(sinner* sinners, int size);
void printArrow(arrow arw);
arrow* updateArrow(arrow arw, arrow* arws, int size);
bool isASubset(arrow arw, arrow* arws, int size);
int intersection (arrow arw, arrow* arws, int size);

int main()
{
    //note: the join() method changes the arrow in question!!!!


    int survivorCnt = 0;
    long long int maxLen = 0;
    int n;
    cin >> n;
    sinner* sinners = (sinner *)malloc(n*sizeof(sinner));
    int arwSize = 0;
    arrow* arrows = (arrow*)malloc(arwSize*sizeof(arrow));
    for (int i = 0; i < n; i ++)
    {
        sinner temp;
        temp.targeted = 0;
        cin >> temp.clawlen;
        if (temp.clawlen > maxLen) maxLen = temp.clawlen;
        sinners[i] = temp;
    }

    bool drawn = 0;
    //draws an arrow for every sinner with a claw of maximum length
    for (int i = n-1; i >= 0; i --)
    {
        if (sinners[i].clawlen == maxLen && sinners[i].clawlen > 0)
        {
            int start;
            if (i - maxLen < 0) start = 0;
            else start = i - maxLen;
            arrow temp(start, i);
            if (isASubset(temp, arrows, arwSize)) continue;
            else
            {
                arrows = updateArrow(temp, arrows, arwSize);
                arwSize ++;
            }
            
        }
    }
    // for (int i = 0; i < arwSize; i ++)
    // {
    //     printArrow(arrows[i]);
    // }

    //takes care of the rest of the sinners hopefully
    for (int i = 0; i < n; i++)
    {
        if (sinners[i].clawlen > 0)
        {
            int start;
                if (i - sinners[i].clawlen < 0) start = 0;
                else start = i - sinners[i].clawlen;
                arrow temp(start, i);
            bool isSub = isASubset(temp, arrows, arwSize);
            if (isSub) {
                continue;
            }
            else
            {
                int itsctn = intersection(temp, arrows, arwSize);
                if ( itsctn != -1)
                {
                    arrows[itsctn] = temp.join(arrows[itsctn]);
                }
                else
                {
                    arrows = updateArrow(temp, arrows, arwSize);
                    arwSize ++;
                }
                // cout << "arrow array size:: " <<arwSize << endl;
                // for (int i = 0; i < arwSize; i ++)
                // {
                //     printArrow(arrows[i]);
                // }
                
            }
        }
    }

    // cout << "arrow array size:: " <<arwSize << endl;
    // for (int i = 0; i < arwSize; i ++)
    // {
    //     printArrow(arrows[i]);
    // }

    for (int i = 0; i < arwSize; i++)
    {
        int itsctn = intersection(arrows[i], arrows, arwSize);
        if (itsctn != -1 && itsctn != i)
        {
            arrows[i] = arrows[itsctn].join(arrows[i]);
            // arrows[i].left = 0; arrows[i].right =0;
        }
    }
    for (int i = 0; i < arwSize; i ++)
    {
        for (int j = i + 1; j < arwSize; j++)
        {
            if( arrows[i].left == arrows[j].left && arrows[i].right == arrows[j].right)
            {
                arrows[j].left = 0;
                arrows[j].right = 0;
            }
        }
    }
    // cout << "arrow array size:: " <<arwSize << endl;
    // for (int i = 0; i < arwSize; i ++)
    // {
    //     printArrow(arrows[i]);
    // }
    int totArrLen = 0;
    for (int i = 0; i < arwSize; i++)
    {
        totArrLen += arrows[i].right - arrows[i].left;
    }
    cout << n - totArrLen;

}

void printSinners(sinner* sinners, int size)
{
    for (int i = 0; i < size; i ++)
    {
        cout << "sinner " << i << " :" << sinners[i].targeted << " " << sinners[i].clawlen << endl;
    }
}

void printArrow(arrow arw)
{
    printf("(%i, %i)\n", arw.left, arw.right);
}

arrow* updateArrow(arrow arw, arrow* arws, int size)
{
    arrow* temp = (arrow*)malloc((size+1)*sizeof(arrow));
    arrow t = arw;
    for (int i = 0; i < size; i ++)
    {
        temp[i] = arws[i];
    }
    temp[size] = arw;
    //printArrow(temp[size]);
    return temp;

}

bool isASubset(arrow arw, arrow* arws, int size)
{
    for (int i = 0; i < size; i ++)
    {
        if( arw.isSubsetOf(arws[i])) return true;
    }
    return false;
}

int intersection (arrow arw, arrow* arws, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ( (arw.right <= arws[i].right && arw.right >= arws[i].left) ||
            (arw.left >= arws[i].left && arw.left <= arws[i].right)) return i;
    }
    return -1;
}
