uniform mat4 u_ModelMatrix;
uniform mat4 u_MvpMatrix;
attribute vec4 a_Pos;
attribute vec4 a_Colr;
varying vec4 v_Color;
void main() {
    gl_Position = u_MvpMatrix * u_ModelMatrix * (a_Pos);
    gl_PointSize = 10.0;
    v_Color = a_Colr;
}