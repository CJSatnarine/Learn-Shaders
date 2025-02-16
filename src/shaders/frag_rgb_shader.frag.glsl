#version 330 core 

out vec4 FragColour;

void main() {
    vec2 pixelPos = gl_FragCoord.xy;

    float x = pixelPos.x / 800.0f;
    float y = pixelPos.y / 800.0f;

    float r = 1 - x + y;
    float g = x + y; 
    float b = 1.5 - y;

    FragColour = vec4(r, g, b, 1.0f);
}
