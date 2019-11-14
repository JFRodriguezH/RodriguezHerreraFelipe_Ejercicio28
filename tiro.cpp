#include <iostream>
#include <fstream>
#include <math.h>

void rk(double h, double & x, double & y, double & vy, double & vx, double & t);
std::ofstream outfile;

double const k = 0.07;
double const n = 2.0;
double const g = 9.81;

double const t_0 = 0.0;
double const y_0 = 0.0;
double const vy_0 = 10.0;
double const x_0 = 0.0;
double const vx_0 = 10.0;

int main(){
	
	double h = 0.01;
	double t = t_0;
	double y = y_0;
	double vy = vy_0;
    double x = x_0;
	double vx = vx_0;
	
	outfile.open("tiro.dat");
    outfile << t << " "<< x << " " << y << " "<< vx << " " << vy << std::endl;
	rk(h, x, y, vx, vy, t);
    while(y>0){
        outfile << t << " "<< x << " " << y << " "<< vx << " " << vy << std::endl;
		rk(h, x, y, vx, vy, t);
    }
    outfile.close();
	
	return 0;
}

/*d^2 x/dt^2 = -k vx^n vx/|V|*/

/*d^2 y/dt^2 = -g -k vy^n vy/|V|*/

void rk(double h, double & x, double & y, double & vx, double & vy, double & t){
    double k1x , k2x, k3x, k4x, k1y, k2y, k3y, k4y, k1vx, k2vx, k3vx, k4vx, k1vy, k2vy, k3vy, k4vy;
    double V = sqrt(vx*vx + vy*vy);
    
    k1x = vx;
    k2x = vx + k1x/2.0;
    k3x = vx + k2x/2.0;
    k4x = vx + k3x;
    
    k1y = vy;
    k2y = vy + k1y/2.0;
    k3y = vy + k2y/2.0;
    k4y = vy + k3y;
    
    k1vx = -k*pow(vx, n)*(vx/V);
    k2vx = -k*pow((vx+(k1vx/2.0)), n)*((vx+(k1vx/2.0))/V);
    k3vx = -k*pow((vx+(k2vx/2.0)), n)*((vx+(k2vx/2.0))/V);
    k4vx = -k*pow((vx+k3vx), n)*((vx+k3vx)/V);
    
    k1vy = -g-k*pow(vy, n)*(vy/V);
    k2vy = -g-k*pow((vy+(k1vy/2.0)), n)*((vy+(k1vy/2.0))/V);
    k3vy = -g-k*pow((vy+(k2vy/2.0)), n)*((vy+(k2vy/2.0))/V);
    k4vy = -g-k*pow((vy+k3vy), n)*((vy+k3vy)/V);
    
    t += h;
    x += (h/6.0)*(k1x + 2.0*k2x + 2.0*k3x + k4x);
    y += (h/6.0)*(k1y + 2.0*k2y + 2.0*k3y + k4y);
    vx += (h/6.0)*(k1vx + 2.0*k2vx + 2.0*k3vx + k4vx);
    vy += (h/6.0)*(k1vy + 2.0*k2vy + 2.0*k3vy + k4vy);
}

/*outfile.open("explicit_01.dat");
    for(int i=0; i<n+1; i++){
        outfile << t << " " << y <<endl;
        t += delta;
        y = expl(y, wDelta);
    }
	outfile << delta << " " << 0 << endl;
    outfile.close();*/