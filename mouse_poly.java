package mouse_poly;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*<applet code="mouse_poly.class" width=500 height=400></applet>*/
public class mouse_poly  extends Applet implements MouseListener,MouseMotionListener
{
	int x[]=new int[30];
	int y[]=new int[30];
	int i=0;
	public void init()
	{
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	public void mouseEntered(MouseEvent m)
	{
		showStatus("Mouse Entered");
	}
	public void mouseExited(MouseEvent m)
	{
	}
	public void mousePressed(MouseEvent m)
	{
		x[i]=m.getX();
		y[i]=m.getY();
		i++	;
	}
	public void mouseReleased(MouseEvent m)
	{

	}
	public void mouseClicked(MouseEvent m)
	{
		switch (m.getClickCount())
		{
			case 2: 			// double-click
				i=0;
				repaint();
				break;
			default: // ignore anything else
				repaint();
				break;
		}
	}
	public void mouseMoved(MouseEvent me)
	{
			
	}
	public void mouseDragged(MouseEvent m)
	{
	}
	public void paint(Graphics g)
	{
		for(int j=0;j<i-1;j++)
		{
			g.drawLine(x[j],y[j],x[j+1],y[j+1]);
		}
	}
}

	