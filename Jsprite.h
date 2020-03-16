#ifndef		_SPRITE_DOT_H_
#define		_SPRITE_DOT_H_


struct 3DVECT8{
	u8 x;   
	u8 y;   
	u8 z;   	
};

struct 3DVECT16{
	u16 x;   
	u16 y;   
	u16 z;   	
};



class Jsprite
{
public:

		Jsprite(const unsigned char bmpArr);

		void initSprite();

		void changeTexture();

private:
		//sprites world location
		struct 3DVECT16 fLoc;  
		

		//sprite dimensions
		u8 fWidth;
		u8 fHeight;

		//whether the sprite is visible or not
		bool fVisibility;

		//current direction		(unit velocity)
		struct 3DVECT8 fDir;

        //speed sprite is travelling
		u8 fSpeed;

		//number of frames of animation
		u8 fFramesOfAnim;

		//current frame of animation
		u8 fTextureIndex;

		//sprite index for this sprite
		u8 fSprite[1]; //Does this mean 1-128? i think so

		const unsigned char* fBmpArray;
        


};

#endif
