function varargout = LineFollowe(varargin)
% LINEFOLLOWE MATLAB code for LineFollowe.fig
%      LINEFOLLOWE, by itself, creates a new LINEFOLLOWE or raises the existing
%      singleton*.
%
%      H = LINEFOLLOWE returns the handle to a new LINEFOLLOWE or the handle to
%      the existing singleton*.
%
%      LINEFOLLOWE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LINEFOLLOWE.M with the given input arguments.
%
%      LINEFOLLOWE('Property','Value',...) creates a new LINEFOLLOWE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before LineFollowe_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to LineFollowe_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help LineFollowe

% Last Modified by GUIDE v2.5 10-Feb-2020 21:33:08

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @LineFollowe_OpeningFcn, ...
                   'gui_OutputFcn',  @LineFollowe_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before LineFollowe is made visible.
function LineFollowe_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to LineFollowe (see VARARGIN)

% Choose default command line output for LineFollowe
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

set_param('lineFollower','SimulationCommand','start');
set_param('lineFollower','SimulationCommand','update');
set_param('lineFollower','SimulationMode','external');

% UIWAIT makes LineFollowe wait for user response (see UIRESUME)
% uiwait(handles.figure1);
ha = axes('units','normalized', 'position',[0 0 1 1]);
% Move the background axes to the bottom
uistack(ha,'bottom');
% Load in a background image and display it using the correct colors
% The image used below, is in the Image Processing Toolbox.  If you do not have %access to this toolbox, you can use another image file instead.
I=imread('background.jpg');
hi = imagesc(I)
colormap gray
% Turn the handlevisibility off so that we don’t inadvertently plot into the axes again
% Also, make the axes invisible
set(ha,'handlevisibility','off','visible','off')

% --- Outputs from this function are returned to the command line.
function varargout = LineFollowe_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in down.
function down_Callback(hObject, eventdata, handles)
% hObject    handle to down (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load_system('lineFollower')
set_param('lineFollower','SimulationCommand','start')
set_param('lineFollower','SimulationCommand','update')
set_param('lineFollower/Constant','Value','1')


% --- Executes on button press in up.
function up_Callback(hObject, eventdata, handles)
% hObject    handle to up (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load_system('lineFollower')
set_param('lineFollower','SimulationCommand','start')
set_param('lineFollower','SimulationCommand','update')
set_param('lineFollower/Constant','Value','0')

% --- Executes on button press in left.
function left_Callback(hObject, eventdata, handles)
% hObject    handle to left (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load_system('lineFollower')
set_param('lineFollower','SimulationCommand','start')
set_param('lineFollower','SimulationCommand','update')
set_param('lineFollower/Constant','Value','3')

% --- Executes on button press in right.
function right_Callback(hObject, eventdata, handles)
% hObject    handle to right (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load_system('lineFollower')
set_param('lineFollower','SimulationCommand','start')
set_param('lineFollower','SimulationCommand','update')
set_param('lineFollower/Constant','Value','2')

% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over down.
function down_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to down (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over up.
function up_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to up (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton5.
%Manual%%%%%%%%%%%%%%%%%%%%%%%%%
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load_system('LineFollower')
set_param('LineFollower','SimulationCommand','start')
set_param('LineFollower','SimulationCommand','update')
set_param('LineFollower/Constant1','Value','1');


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over pushbutton5.
function pushbutton5_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton6.
%Line%%%%%%%%%%%%%%%%%%%%%%%%%
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load_system('LineFollower')
set_param('LineFollower','SimulationCommand','start')
set_param('LineFollower','SimulationCommand','update')
set_param('LineFollower/Constant1','Value','0');
