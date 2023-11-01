package DrFrankenstein;

/*import robocode.HitByBulletEvent;*/
import robocode.HitRobotEvent;
import robocode.Robot;
import robocode.ScannedRobotEvent;
import robocode.WinEvent;
import robocode.*;
import java.awt.*;
import static robocode.util.Utils.normalRelativeAngleDegrees;
/**
 * Frankenstein - a robot by Nathan Santana Domingos
 */
public class Frankenstein extends AdvancedRobot
{
	public void run() {
		
		setColors(Color.black, Color.black, Color.white, Color.blue, Color.white);
		setAdjustGunForRobotTurn(true);		

		
		setTurnRight(90);
		while(true) {
			setTurnGunRight(360);
			setTurnRight(45);
			ahead(100);
		}
	}
	
	public void onScannedRobot(ScannedRobotEvent e) {
				
		double absoluteBearing = getHeading() + e.getBearing();
		double bearingFromGun = normalRelativeAngleDegrees(absoluteBearing - getGunHeading());

		if (Math.abs(bearingFromGun) <= 3) {
			setTurnGunRight(bearingFromGun);
			if (getGunHeat() == 0) {
				fire(Math.min(3 - Math.abs(bearingFromGun), getEnergy() - .1));
			}
		}else {
			setTurnGunRight(bearingFromGun);
		}
		if (bearingFromGun == 0) {
			scan();
		}
	}
	
	public void onHitWall(HitWallEvent e) {
		setTurnRight(30);
		back(110);
	}
	
	public void onHitRobot(HitRobotEvent e) {
		double turnGunAmt = normalRelativeAngleDegrees(e.getBearing() + getHeading() - getGunHeading());

		turnGunRight(turnGunAmt);
		fire(2);
	}
	
	public void onWin(WinEvent e) {
		turnGunRight(360000);
	}
}
