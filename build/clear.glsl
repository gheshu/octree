#version 430 core

layout(local_size_x = 8, local_size_y = 8) in;

layout(binding = 0, rg32f) uniform image2D dbuf;

void main(){
	ivec2 pix = ivec2(gl_GlobalInvocationID.xy);  
	ivec2 size = imageSize(dbuf);
	if (pix.x >= size.x || pix.y >= size.y) return;
	imageStore(dbuf, pix, vec4(999999.0f, -1.0f, 0.0f, 0.0f));
}
