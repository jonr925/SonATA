/*
 * Licensed under the GPL License. You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://probe.jstripe.com/d/license.shtml
 *
 *  THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 *  WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

package org.jstripe.tomcat.probe.controllers.logs;

import org.jstripe.tomcat.probe.model.FollowedFile;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.ParameterizableViewController;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.sql.Timestamp;

public class UpdateFileInfoController extends ParameterizableViewController {

    private String fileAttributeName;

    public String getFileAttributeName() {
        return fileAttributeName;
    }

    public void setFileAttributeName(String fileAttributeName) {
        this.fileAttributeName = fileAttributeName;
    }

    protected ModelAndView handleRequestInternal(HttpServletRequest request, HttpServletResponse response) throws Exception {

       System.out.println("UpdateFileInfoController");

        if (request.getSession() != null) {
            FollowedFile ff = (FollowedFile) request.getSession().getAttribute(fileAttributeName);
            if (ff != null) {
                File f = new File(ff.getFileName());
                if (f.exists()) {
                    ff.setLastModified(new Timestamp(f.lastModified()));
                    ff.setSize(f.length());
                    request.getSession().setAttribute(fileAttributeName, ff);
                } else {

		   //logger.debug("File "+ff.getFileName() + " does not exist");
		   System.out.println("UpdateFileInfoController File "+ff.getFileName() + " does not exist");
                }
            } else {
	       
	       //logger.debug(fileAttributeName + " attribute is not in session");
                System.out.println("UpdateFileInfoController " + fileAttributeName + " attribute is not in session");
            }
        }
        return new ModelAndView(getViewName());
    }
}
