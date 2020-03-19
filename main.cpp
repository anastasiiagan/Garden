//Anastasiia Ganusina
#include <iostream>

using namespace std;

/*class GARDEN_CLASS;*/
class WOOD_CLASS;
class BRANCH_CLASS;
class FRUIT_CLASS;

class GARDEN_CLASS
{
    private:
    unsigned int WeightOfG;
    unsigned int QuantityOfW;
    unsigned int QuantityOfB;
    unsigned int QuantityOfF;
    unsigned int lowestID;
    WOOD_CLASS* minW;
    WOOD_CLASS* firstW;
    WOOD_CLASS* lastW;
public:
    GARDEN_CLASS();

    ~GARDEN_CLASS();

    unsigned int getWoodsTotal(void);
    unsigned int getBranchesTotal(void);
    unsigned int getFruitsTotal(void);
    unsigned int getWeightsTotal(void);

    void displayWoodsG();
    unsigned int lowId();

    void plantWood(void);
    void extractWood(unsigned int );
    void growthGarden(void);
    void fadeGarden(void);
    void harvestGarden(unsigned int);
    void cloneWood(unsigned int );

    WOOD_CLASS* getWoodPointer(unsigned char );
    void addWeight(unsigned int);
    void subWeight(unsigned int);
    void addQFruits(unsigned int);
    void subQFruits(unsigned int);
    void addQBranches(unsigned int);
    void subQBranches(unsigned int);
};
class WOOD_CLASS
{
    private:
    unsigned int WeightOfW;
    unsigned int QuantityOfB;
    unsigned int QuantityOfF;
    unsigned int height;
    unsigned int id;
    BRANCH_CLASS* firstB;
    WOOD_CLASS* next_W;
    WOOD_CLASS* prev_W;
    GARDEN_CLASS* parentW;

public:
    WOOD_CLASS();
    ~WOOD_CLASS();
    void cloneBranch(BRANCH_CLASS*);
    WOOD_CLASS(const WOOD_CLASS&);

    BRANCH_CLASS* getFirst();

    void setId(unsigned int);
    void setParent(GARDEN_CLASS*);


    unsigned int getBranchesTotal(void);

    unsigned int getFruitsTotal(void);

    unsigned int getWeightsTotal(void);

    unsigned int getNumber(void);

    unsigned int getHeight(void);

    void displayWood();


    void growthWood(void);
    void fadeWood(void);

    void harvestWood(unsigned int );

    void cutWood(unsigned int);

    GARDEN_CLASS* getGardenPointer(void);

    BRANCH_CLASS* getBranchPointer(unsigned int);

    WOOD_CLASS* getNext();
    void setNext(WOOD_CLASS*);
    WOOD_CLASS* getPrev();
    void setPrev(WOOD_CLASS*);

    void addWeight(unsigned int);
    void subWeight(unsigned int);
    void addQFruits(unsigned int);
    void subQFruits(unsigned int);

};
class BRANCH_CLASS
{
    private:
    unsigned int WeightOfBranch;
    unsigned int length;
    unsigned int height;
    unsigned int QuantityOfF;
    FRUIT_CLASS* firstF;
    BRANCH_CLASS* next_B;
    WOOD_CLASS* parentB;

public:
    BRANCH_CLASS();
    /*BRANCH_CLASS(unsigned int h,WOOD_CLASS *parent)//
    {
    }*/

    void setHeight(unsigned int);
    void setParentB(WOOD_CLASS*);

    ~BRANCH_CLASS();

    BRANCH_CLASS(const BRANCH_CLASS&);

    unsigned int getFruitsTotal(void);

    unsigned int getWeightsTotal(void);

    unsigned int getHeight(void);

    unsigned int getLength(void);

    void displayBranch();

    void growthBranch(void);

    void fadeBranch(void);

    void harvestBranch(unsigned int );

    void cutBranch(unsigned int );

    FRUIT_CLASS* getFruitPointer(unsigned int );

    WOOD_CLASS* getWoodPointer(void);
    FRUIT_CLASS* getFirstF(void);

    BRANCH_CLASS* getNext(void);

    void setNext(BRANCH_CLASS*);

    void addWeight();
    void subWeight(unsigned int);
};


class FRUIT_CLASS{
private:
    unsigned int WeightOfF;
    unsigned int length;
    FRUIT_CLASS *next_F;
    BRANCH_CLASS *parentF;

public:
    FRUIT_CLASS()
    {
        WeightOfF = 0;
        length = 0;
        next_F = NULL;
        parentF = NULL;
    }

    ~FRUIT_CLASS(){}
    FRUIT_CLASS(const FRUIT_CLASS & cloneF)
        {
            WeightOfF = cloneF.WeightOfF;
            length = cloneF.length;
            next_F = NULL;
            parentF = cloneF.parentF;
        }

    void setLength(unsigned int l){if(l%2==0 && l>0)length = l;}
    void setWeight(unsigned int w){WeightOfF = w;}

    void setParentF(BRANCH_CLASS *parent){parentF = parent;}

    FRUIT_CLASS* getNextF(void){return next_F;}
    void setNextF(FRUIT_CLASS *temp){next_F = temp;}

    unsigned int getLength(void){return length;}//ok

    unsigned int getWeight(void){return WeightOfF;}//ok

    void growthFruit(void){WeightOfF++;if(parentF!=NULL)    parentF->addWeight();}

    void fadeFruit(void){if(WeightOfF>0){ WeightOfF--;if(parentF!=NULL)  parentF->subWeight(1);}}

    void pluckFruit(void){if(parentF!=NULL)     parentF->subWeight(WeightOfF);WeightOfF=0;}

    BRANCH_CLASS* getBranchPointer(void){return parentF;}//ok

};


    BRANCH_CLASS::BRANCH_CLASS()
    {
        WeightOfBranch = 0;
        length = 0;
        height = 0;
        QuantityOfF = 0;
        firstF = NULL;
        next_B = NULL;
        parentB = NULL;
    }

    void BRANCH_CLASS::setHeight(unsigned int h){height = h;}
    void BRANCH_CLASS::setParentB(WOOD_CLASS *parent){parentB = parent;}

    BRANCH_CLASS::~BRANCH_CLASS()
    {
        FRUIT_CLASS *temp = firstF;
        FRUIT_CLASS *temp2;
        while(temp)
        {
            temp2 = temp;
            temp = temp->getNextF();
            delete temp2;
        }
    }

    BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS & cloneB)
    {
            WeightOfBranch = cloneB.WeightOfBranch;
            QuantityOfF = cloneB.QuantityOfF;
            length = cloneB.length;
            height = cloneB.height;
            next_B = NULL;
            parentB = cloneB.parentB;//ma byc w wood!!
            if(cloneB.firstF==NULL)
                firstF = NULL;
            else{
                FRUIT_CLASS *nowe = new FRUIT_CLASS;
                FRUIT_CLASS *temp = cloneB.firstF;
                firstF = new FRUIT_CLASS(*temp);
                firstF ->setParentF(this);
                FRUIT_CLASS *tempN = firstF;
                //FRUIT_CLASS *nowe;
                while(temp->getNextF())
                {
                    nowe = new FRUIT_CLASS(*temp->getNextF());
                    tempN->setNextF(nowe);
                    tempN->getNextF()->setParentF(this);
                    tempN = tempN->getNextF();
                    temp = temp->getNextF();
                }
                tempN->setNextF(NULL);
            }
    }


    unsigned int BRANCH_CLASS::getFruitsTotal(void){return QuantityOfF;}

    unsigned int BRANCH_CLASS::getWeightsTotal(void){return WeightOfBranch;}

    unsigned int BRANCH_CLASS::getHeight(void){return height;}

    unsigned int BRANCH_CLASS::getLength(void){return length;}

    void BRANCH_CLASS::displayBranch()
    {
        FRUIT_CLASS *temp = firstF;
        cout<<"Ilosc owocow "<<QuantityOfF<<endl;
        cout<<"Wysokosc "<<height<<endl;
        cout<<"Szerokosc "<<length<<endl;
        cout<<"Waga "<<WeightOfBranch<<endl;
        while(temp)
        {
            cout<<temp->getLength()<<" ";
            cout<<temp->getWeight()<<endl;
            temp = temp->getNextF();
        }
    }

    void BRANCH_CLASS::growthBranch(void)//ok
    {

        FRUIT_CLASS *temp = firstF;

        length++;
        for(unsigned int i=1;i<QuantityOfF;i++ )
        {
            temp->growthFruit();
            temp = temp->getNextF();
        }
        if(length%2==0)
        {
            QuantityOfF++;
            if(parentB!=NULL)   parentB->addQFruits(1);
            FRUIT_CLASS *newF = new FRUIT_CLASS();
            newF->setLength(length);
            newF->setParentF(this);
            if(temp!=NULL)
            {
                temp->growthFruit();
                temp->setNextF(newF);
            }
            else{
                firstF = newF;
            }
        }else{
            if(temp!=NULL)
            {
                temp->growthFruit();
            }
        }

    }

    void BRANCH_CLASS::fadeBranch(void)
    {
        if(length>0)
    {
        FRUIT_CLASS *temp = firstF;
        length--;
        if(length%2==0)
        {
            while(temp)
            {
                temp->fadeFruit();
                temp = temp->getNextF();
            }
        }
        else
        {
            if(temp)
            {
                QuantityOfF--;//odwolaj sie do wood
                if(parentB!=NULL)   parentB->subQFruits(1);
                if(temp->getNextF())
                {
                    while(temp->getNextF()->getNextF())
                    {
                        temp->fadeFruit();
                        temp = temp->getNextF();
                    }
                    temp->fadeFruit();
                    temp->getNextF()->pluckFruit();
                    temp->setNextF(NULL);
                }
                else
                {
                    temp->pluckFruit();
                    firstF = NULL;
                }

            }
        }
    }
    }

    void BRANCH_CLASS::harvestBranch(unsigned int w)
    {
        FRUIT_CLASS *temp = firstF;
        while(temp)
        {
            if(temp->getWeight()>=w)
            {
                temp->pluckFruit();
            }
            temp = temp->getNextF();
        }
    }

    void BRANCH_CLASS::cutBranch(unsigned int l)
    {

        if(firstF && l>=0)
        {
            length = l;
            FRUIT_CLASS *temp = firstF;
            unsigned int q=0;
            if(temp->getLength()>l)
            {
                while(temp)
                {
                    q++;
                    temp->pluckFruit();
                    temp = temp->getNextF();
                }
                firstF = NULL;
            }
            else{
                FRUIT_CLASS *temp2;
                while(temp->getNextF())
                {
                    if(temp->getNextF()->getLength()>l)
                    {
                    temp2 = temp->getNextF();
                        while(temp2)
                        {
                        q++;

                        temp2->pluckFruit();
                        temp2 = temp2->getNextF();
                        }
                    temp->setNextF(NULL);
                    }else   temp = temp->getNextF();
                }
            }
            QuantityOfF-=q;
            if(parentB!=NULL)   parentB->subQFruits(q);
            //tu dodaj warunek na drzewo
        }

    }

    FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int t)//chyba tak
    {
        FRUIT_CLASS *temp = firstF;
        FRUIT_CLASS *temp2 = NULL;
        while(temp)
        {
            if(temp->getLength()==t)
            {
                temp2 = temp;
            }
            temp=temp->getNextF();
        }
        return temp2;

    }

    WOOD_CLASS* BRANCH_CLASS::getWoodPointer(void)
    {
        return parentB;
    }

    FRUIT_CLASS* BRANCH_CLASS::getFirstF(void){return firstF;}

    BRANCH_CLASS* BRANCH_CLASS::getNext(void){return next_B;}

    void BRANCH_CLASS::setNext(BRANCH_CLASS *temp){next_B=temp;}

    void BRANCH_CLASS::addWeight(){WeightOfBranch++;if(parentB!=NULL)   parentB->addWeight(1);}
    void BRANCH_CLASS::subWeight(unsigned int w){WeightOfBranch-=w;if(parentB!=NULL)   parentB->subWeight(w);}



WOOD_CLASS::WOOD_CLASS()
    {
        WeightOfW = 0;
        QuantityOfB = 0;
        QuantityOfF = 0;
        id = 0;
        height =0;
        firstB =NULL;
        next_W=NULL;
        prev_W = NULL;
        parentW = NULL;

    }

WOOD_CLASS::~WOOD_CLASS()
    {
        BRANCH_CLASS *temp = firstB;
        BRANCH_CLASS *temp2 = firstB;
        while(temp)
        {
            temp2 = temp;
            temp = temp->getNext();
            delete temp2;
        }
    }

BRANCH_CLASS* WOOD_CLASS::getFirst(){return firstB;}

void WOOD_CLASS::cloneBranch(BRANCH_CLASS *cloneit)
{
    if(firstB && cloneit){
            bool t = true;
            BRANCH_CLASS *temp = firstB;
    BRANCH_CLASS *cloneB = new BRANCH_CLASS(*cloneit);
    if(firstB->getLength()==0)
    {
        cloneB->setHeight(firstB->getHeight());
        cloneB->setParentB(this);
        QuantityOfF+=cloneit->getFruitsTotal();
        WeightOfW+=cloneit->getWeightsTotal();
        cloneB->setNext(firstB->getNext());
        if(parentW)
        {
            parentW->addQFruits(cloneit->getFruitsTotal());
            parentW->addWeight(cloneit->getWeightsTotal());
        }
        firstB = cloneB;
        //break;
    }else{
    while(temp->getNext()!=NULL && t)
    {
        if(temp->getNext()->getLength()==0)
        {
            cloneB->setHeight(temp->getNext()->getHeight());
            cloneB->setParentB(this);
            QuantityOfF+=cloneit->getFruitsTotal();
            WeightOfW+=cloneit->getWeightsTotal();
            if(parentW)
            {
            parentW->addQFruits(cloneit->getFruitsTotal());
            parentW->addWeight(cloneit->getWeightsTotal());
            }
            cloneB->setNext(temp->getNext()->getNext());
            temp->setNext(cloneB);
            t = false;
        }
        else    temp = temp->getNext();
    }
    }
    }
}

WOOD_CLASS::WOOD_CLASS(const WOOD_CLASS & cloneW)
    {
            WeightOfW = cloneW.WeightOfW;
            QuantityOfF = cloneW.QuantityOfF;
            QuantityOfB = cloneW.QuantityOfB;
            id = 0;//
            height = cloneW.height;
            next_W = NULL;
            prev_W = NULL;
            parentW = cloneW.parentW;//ma byc w wood!!
            if(cloneW.firstB==NULL)
                firstB = NULL;
            else{
                BRANCH_CLASS *nowe = new BRANCH_CLASS;
                BRANCH_CLASS *temp = cloneW.firstB;
                firstB = new BRANCH_CLASS(*temp);
                firstB ->setParentB(this);
                BRANCH_CLASS *tempN = firstB;
                //FRUIT_CLASS *nowe;
                while(temp->getNext())
                {
                    nowe = new BRANCH_CLASS(*temp->getNext());
                    tempN->setNext(nowe);
                    tempN->getNext()->setParentB(this);
                    tempN = tempN->getNext();
                    temp = temp->getNext();
                }
                tempN->setNext(NULL);
            }
    }

void WOOD_CLASS::setId(unsigned int i){id = i;}
void WOOD_CLASS::setParent(GARDEN_CLASS *temp){parentW = temp;}

unsigned int WOOD_CLASS::getBranchesTotal(void){return QuantityOfB;}

unsigned int WOOD_CLASS::getFruitsTotal(void){return QuantityOfF;}

unsigned int WOOD_CLASS::getWeightsTotal(void){return WeightOfW;}

unsigned int WOOD_CLASS::getNumber(void){return id;}

unsigned int WOOD_CLASS::getHeight(void){return height;}

void WOOD_CLASS::displayWood()
    {
        BRANCH_CLASS *temp = firstB;
        cout<<height<<endl;
        cout<<QuantityOfB<<endl;
        while(temp)
        {
            temp->displayBranch();
            cout<<endl;
            temp = temp->getNext();
        }
    }


void WOOD_CLASS::growthWood(void)
    {

        BRANCH_CLASS *temp = firstB;
        height++;


        if(height%3==0)//dodaje galaz
        {
            QuantityOfB++;
            if(parentW!=NULL)   parentW->addQBranches(1);
            BRANCH_CLASS *newB = new BRANCH_CLASS();
            newB->setHeight(height);
            newB->setParentB(this);
            if(temp)
            {
                while(temp->getNext())
                {
                    temp->growthBranch();
                    temp = temp->getNext();
                }
                temp->growthBranch();
                temp->setNext(newB);
            }
            else{
                firstB = newB;
            }
        }
        else
        {
            while(temp)
            {
                temp->growthBranch();
                temp = temp->getNext();
            }
        }


    }
void WOOD_CLASS::fadeWood(void)
    {
        BRANCH_CLASS *temp = firstB;
        if(height>0)
        {
        height--;
        if(height%3==2)//usuwam
        {
            if(temp)
            {
                QuantityOfB--;//tutaj odwolaj sie do garden
                if(parentW!=NULL)   parentW->subQBranches(1);
                if(temp->getNext())
                {
                    while(temp->getNext()->getNext())
                    {
                        if(temp->getLength()>0)
                        {
                            temp->fadeBranch();
                        }
                        temp = temp->getNext();
                    }
                    if(temp->getLength()>0)
                    {
                        temp->fadeBranch();
                    }
                    temp->getNext()->cutBranch(0);
                    temp->setNext(NULL);
                }
                else
                {
                    temp->cutBranch(0);
                    firstB = NULL;
                }

            }
        }
        else
        {
           while(temp)
            {
                if(temp->getLength()>0)
                {
                    temp->fadeBranch();
                }
                temp = temp->getNext();
            }
        }
        }
    }

void WOOD_CLASS::harvestWood(unsigned int w)
    {
        BRANCH_CLASS *temp = firstB;
        while(temp)
        {
            temp->harvestBranch(w);
            temp = temp->getNext();
        }
    }

void WOOD_CLASS::cutWood(unsigned int h)
    {
        height = h;
        BRANCH_CLASS *temp = firstB;
        BRANCH_CLASS *temp2;
        unsigned int Q=0;
        if(temp)
        {
            if(temp->getHeight()>h)
            {
                while(temp)
                {
                    temp->cutBranch(0);
                    Q++;
                    temp = temp->getNext();
                }
                firstB = NULL;
            }
            else{
                while(temp->getNext())
                {
                    if(temp->getNext()->getHeight()>h)
                    {
                    temp2 = temp->getNext();
                        while(temp2)
                        {
                        temp2->cutBranch(0);
                        Q++;
                        temp2 = temp2->getNext();
                        }
                    temp->setNext(NULL);
                    }else   temp = temp->getNext();
                }
            }
        }
        QuantityOfB -= Q;//odwolaj sie do qarden
        if(parentW!=NULL)   parentW->subQBranches(Q);
    }

//void WOOD_CLASS::cloneBranch(BRANCH_CLASS *temp){}

GARDEN_CLASS* WOOD_CLASS::getGardenPointer(void){return parentW;}

BRANCH_CLASS* WOOD_CLASS::getBranchPointer(unsigned int h)
    {
        BRANCH_CLASS *temp = firstB;
        BRANCH_CLASS *temp2 = NULL;
        while(temp)
        {
            if(temp->getHeight()==h)
            {
                temp2 = temp;
            }
            temp=temp->getNext();
        }
        return temp2;
    }

WOOD_CLASS* WOOD_CLASS::getNext(){return next_W;}
void WOOD_CLASS::setNext(WOOD_CLASS *temp){next_W=temp;}
WOOD_CLASS* WOOD_CLASS::getPrev(){return prev_W;}
void WOOD_CLASS::setPrev(WOOD_CLASS *temp){prev_W=temp;}

void WOOD_CLASS::addWeight(unsigned int w){WeightOfW+=w;if(parentW!=NULL)   parentW->addWeight(w);}
void WOOD_CLASS::subWeight(unsigned int w){WeightOfW-=w;if(parentW!=NULL)   parentW->subWeight(w);}
void WOOD_CLASS::addQFruits(unsigned int b){QuantityOfF+=b;if(parentW!=NULL)   parentW->addQFruits(b);}
void WOOD_CLASS::subQFruits(unsigned int b){QuantityOfF-=b;if(parentW!=NULL)   parentW->subQFruits(b);}




GARDEN_CLASS::GARDEN_CLASS()
    {
        WeightOfG = 0;
        QuantityOfB = 0;
        QuantityOfF = 0;
        QuantityOfW = 0;
        lowestID = 0;
        minW = NULL;
        firstW = NULL;
        lastW = NULL;
    }

GARDEN_CLASS::~GARDEN_CLASS()
    {
        WOOD_CLASS *temp = firstW;
        //WOOD_CLASS *temp2 = firstW;
        while(temp)
        {
            firstW = temp->getNext();
            delete temp;
            temp = firstW;
        }
        lastW = NULL;
    }

unsigned int GARDEN_CLASS::getWoodsTotal(void){return QuantityOfW;}

unsigned int GARDEN_CLASS::getBranchesTotal(void){return QuantityOfB;}

unsigned int GARDEN_CLASS::getFruitsTotal(void){return QuantityOfF;}

unsigned int GARDEN_CLASS::getWeightsTotal(void){return WeightOfG;}

void GARDEN_CLASS::displayWoodsG()
    {
        WOOD_CLASS* temp = firstW;
        cout<<QuantityOfW<<endl;
        cout<<WeightOfG<<endl<<endl;
        while(temp){
            cout<<temp->getNumber()<<endl;
            cout<<temp->getBranchesTotal()<<endl;
            cout<<temp->getFruitsTotal()<<endl;
            cout<<temp->getWeightsTotal()<<endl<<endl;
            temp=temp->getNext();
        }
        cout<<endl<<endl;
    }

unsigned int GARDEN_CLASS::lowId()
    {

        if(firstW==NULL || lowestID<firstW->getNumber())
        {
            minW = NULL;
            lowestID = 0;
        }else{
        if(lowestID>lastW->getNumber())
        {
            minW = lastW;
        }else{
            WOOD_CLASS *temp;
            if(minW!=NULL)  temp = minW;
            else    temp = firstW;
            while(temp)
            {
            if(temp->getNumber()==lowestID)
            {
                minW = temp;
                lowestID++;
            }
            temp = temp->getNext();
            }
        }
        }
        return lowestID;
    }

void GARDEN_CLASS::cloneWood(unsigned int i)
{

if(firstW)
{
        WOOD_CLASS *temp = firstW;
        WOOD_CLASS *cloneW;
        while(temp)
        {
            if(temp->getNumber()==i)
            {
                break;
            }
            else    temp=temp->getNext();
        }
        if(temp!=NULL)
        {
            WeightOfG += temp->getWeightsTotal();
            QuantityOfB += temp->getBranchesTotal();
            QuantityOfF += temp->getFruitsTotal();
            cloneW = new WOOD_CLASS(*temp);
            cloneW->setParent(this);
            QuantityOfW++;
            unsigned int id = lowId();
            cloneW->setId(id);
            lowestID++;
            if(id<firstW->getNumber())
            {
                cloneW->setNext(firstW);
                firstW->setPrev(cloneW);
                firstW = cloneW;
                minW = firstW;
            }
            else{
                cloneW->setPrev(minW);//
                if(minW->getNext())
                {
                    cloneW->setNext(minW->getNext());//
                    minW->getNext()->setPrev(cloneW);
                    minW->setNext(cloneW);
                    minW = cloneW;
                }
                else{
                    minW->setNext(cloneW);
                    lastW = cloneW;
                    minW = lastW;
                }
            }
        }
}
}

void GARDEN_CLASS::plantWood(void)
{
    WOOD_CLASS *newW = new WOOD_CLASS();
    QuantityOfW++;
        unsigned int id = lowId();
        newW->setId(id);
        newW->setParent(this);
        lowestID++;
        if(firstW==NULL)
        {
            firstW = newW;
            lastW = newW;
            minW = lastW;
        }else{
            if(id<firstW->getNumber())
            {
                newW->setNext(firstW);
                firstW->setPrev(newW);
                firstW = newW;
                minW = firstW;
            }
            else{
                newW->setPrev(minW);//
                if(minW->getNext())
                {
                    newW->setNext(minW->getNext());//
                    minW->getNext()->setPrev(newW);
                    minW->setNext(newW);
                    minW = newW;
                }
                else{
                    minW->setNext(newW);
                    lastW = newW;
                    minW = lastW;
                }
            }
        }
        //minW = newW;
}

void GARDEN_CLASS::extractWood(unsigned int i)
{
    if(firstW && firstW->getNumber()<=i && lastW->getNumber()>=i)
    {
        WOOD_CLASS *tt;
        if(i==firstW->getNumber())
        {
            QuantityOfW--;
            tt = firstW;
            if(lowestID>i)
            {
                lowestID = i;
                minW = NULL;
            }
            QuantityOfF-=tt->getFruitsTotal();
            QuantityOfB-=tt->getBranchesTotal();
            WeightOfG-=tt->getWeightsTotal();
            //tt->cutWood(0);
            firstW = firstW->getNext();
            delete tt;
            if(firstW) firstW->setPrev(NULL);
            else{
                lastW = NULL;
            }
        }
        else{
        if(lastW->getNumber()==i)
        {
            QuantityOfW--;
            tt = lastW;
            //tt->cutWood(0);
            lastW = lastW->getPrev();
            QuantityOfF-=tt->getFruitsTotal();
            QuantityOfB-=tt->getBranchesTotal();
            WeightOfG-=tt->getWeightsTotal();
            delete tt;
            if(lowestID>i)
            {
                lowestID = i;
                minW = lastW;
            }
            if(lastW)   lastW->setNext(NULL);
            else
            {
                firstW = NULL;
            }
        }
        else{
            unsigned int p1 = i - firstW->getNumber();
            unsigned int p2 = lastW->getNumber() - i;
            WOOD_CLASS *temp;
            /*if(p1<p2)
            {*/
                temp = firstW;
                bool t =true;
                while(temp->getNext() && t)
                {
                    if(temp->getNext()->getNumber()==i)
                    {
                        tt = temp->getNext();
                        QuantityOfF-=tt->getFruitsTotal();
                        QuantityOfB-=tt->getBranchesTotal();
                        WeightOfG-=tt->getWeightsTotal();
                        //tt->cutWood(0);
                        temp->setNext(temp->getNext()->getNext());
                        delete tt;
                        if(temp->getNext())     temp->getNext()->setPrev(temp);//niepotrzebny warunek
                        if(lowestID>i)
                        {
                            lowestID = i;
                            minW = temp;
                        }
                        QuantityOfW--;
                        t = false;
                    }
                    if(temp->getNext()->getNumber()>i)  t = false;
                    temp = temp->getNext();
                }
            /*}else{
                temp = lastW;
                bool t = true;
                while(temp->getPrev() && t)
                {
                    if(temp->getPrev()->getNumber()==i)
                    {
                        tt = temp->getPrev();
                        tt->cutWood(0);
                        temp->setPrev(temp->getPrev()->getPrev());//W tej linii!!!!!!!!!!
                        delete tt;
                        if(temp->getPrev()) temp->getPrev()->setNext(temp);


                        if(lowestID>i)
                        {
                            lowestID = i;
                            minW = temp->getPrev();
                        }
                        QuantityOfW--;
                        t = false;
                    }
                    if(temp->getPrev()->getNumber()<i)  t = false;
                    temp = temp->getPrev();
                }
            }*/

        }
    }
    }
}

void GARDEN_CLASS::growthGarden(void)
{
    WOOD_CLASS *temp = firstW;
        if(temp!=NULL)
        {
            while(temp)
            {
                temp->growthWood();
                temp = temp->getNext();
            }
        }
}

void GARDEN_CLASS::fadeGarden(void)
{
    WOOD_CLASS *temp = firstW;
        if(temp!=NULL)
        {
            while(temp)
            {
                if(temp->getHeight()>0)
                {
                temp->fadeWood();
                }
                temp = temp->getNext();
            }
        }
}

void GARDEN_CLASS::harvestGarden(unsigned int w)
{
    WOOD_CLASS *temp = firstW;
        if(temp!=NULL)
        {
            while(temp)
            {
                temp->harvestWood(w);
                temp = temp->getNext();
            }
        }
}


WOOD_CLASS* GARDEN_CLASS::getWoodPointer(unsigned char i)
{
    WOOD_CLASS *temp2 = NULL;
        if(firstW)
        {
            WOOD_CLASS *temp = firstW;
            if(i<(lastW->getNumber()-i))
            {
              while(temp)
              {
                if(temp->getNumber()==i)
              {
                temp2 = temp;
                break;
              }
              temp=temp->getNext();
              }
           }else
           {
               temp = lastW;
               while(temp)
              {
                if(temp->getNumber()==i)
              {
                temp2 = temp;
                break;
              }
              temp=temp->getPrev();
              }
            }
        }
        return temp2;
}


void GARDEN_CLASS::addWeight(unsigned int w){WeightOfG+=w;}
void GARDEN_CLASS::subWeight(unsigned int w){WeightOfG-=w;}
void GARDEN_CLASS::addQFruits(unsigned int b){QuantityOfF+=b;}
void GARDEN_CLASS::subQFruits(unsigned int b){QuantityOfF-=b;}
void GARDEN_CLASS::addQBranches(unsigned int b){QuantityOfB+=b;}
void GARDEN_CLASS::subQBranches(unsigned int b){QuantityOfB-=b;}


int main()
{
    WOOD_CLASS tree1;
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.growthWood();
      tree1.cutWood(12);
      //tree1.getBranchPointer(6)->displayBranch();
      WOOD_CLASS tree2;
      tree2.growthWood();
      tree2.growthWood();
      //tree2.growthWood();
      tree2.cloneBranch(tree1.getBranchPointer(3));
      tree2.displayWood();



 WOOD_CLASS tree2;
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      tree2.growthWood();
      //tree1.cutWood(12);
      cout<<"wysokosc: "<<tree1.getHeight()<<endl;
      cout<<"dlugosc 1. galezi: "<<tree1.getBranchPointer(3)->getLength()<<endl;
      cout<<"ilosc galezi: "<<tree1.getBranchesTotal()<<endl;
      cout<<"ilosc owocow na drzewie: "<<tree1.getFruitsTotal()<<endl;
      cout<<"masa owocow na drzewie: "<<tree1.getWeightsTotal()<<endl<<endl;
      //tree1.displayWood();



      tree1.cutWood(12);
      cout<<"wysokosc: "<<tree1.getHeight()<<endl;
      cout<<"dlugosc 1. galezi: "<<tree1.getBranchPointer(3)->getLength()<<endl;
      cout<<"ilosc galezi: "<<tree1.getBranchesTotal()<<endl;
      cout<<"ilosc owocow na drzewie: "<<tree1.getFruitsTotal()<<endl;
      cout<<"masa owocow na drzewie: "<<tree1.getWeightsTotal()<<endl;

      cout<<tree1.getHelpW()<<endl;


      WOOD_CLASS *w = new WOOD_CLASS();
    w->growthWood();
    w->growthWood();
    w->growthWood();
    w->growthWood();
    w->growthWood();
    w->growthWood();
    BRANCH_CLASS *b = new BRANCH_CLASS();
    b->growthBranch();
    b->growthBranch();
    b->growthBranch();
    b->growthBranch();
    b->growthBranch();
    b->cutBranch(2);
    b->growthBranch();
    b->growthBranch();
    b->growthBranch();
    b->displayBranch();cout<<endl<<endl;
    w->cloneBranch(b);
    w->displayWood();

    return 0;
}
